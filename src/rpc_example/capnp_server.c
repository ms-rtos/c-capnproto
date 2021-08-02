/*
 * Copyright (c) 2015-2020 ACOINFO Co., Ltd.
 * All rights reserved.
 *
 * Detailed license information can be found in the LICENSE file.
 *
 * File: capnp_client.c c-capnproto server.
 *
 * Author: Jiao.jinxing <jiaojinxing@acoinfo.com>
 *
 */

#include <ms_rtos.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#include "capnp_c.h"
#include "fileproto.capnp.h"

static capn_text chars_to_text(const char *chars)
{
    return  (capn_text) {.len = (int) strlen(chars),
                         .str = chars,
                         .seg = NULL,
                        };
}

/* Handle one arriving client connection.
 * Clients are expected to send a ListFilesRequest, terminated by a '0'.
 * Server will respond with a ListFilesResponse message.
 */
void handle_connection(int read_fd, int write_fd)
{
    static ms_uint8_t buf[4096];
    ms_ssize_t sz = 0;
    char abs_path[256];
    char *p_path_name;
    MS_DIR *directory = NULL;

    /* Decode the message from the client and open the requested directory. */
    {
        // Deserialize `buf[0..sz-1]` to `rp`.
        struct capn rc;
        int init_mem_ret;
        ListFilesRequest_ptr rroot;
        struct ListFilesRequest request;

        sz = ms_io_read(read_fd, buf, 4096);
        if (sz <= 0) {
            ms_printf("ms_io_read() read ListFilesRequest failed!\n");
            abort();
        }

        init_mem_ret = capn_init_mem(&rc, buf, sz, 0 /* packed */);
        if (init_mem_ret != 0) {
            ms_printf("capn_init_mem() failed!\n");
            abort();
        }

        rroot.p = capn_getp(capn_root(&rc), 0 /* off */, 1 /* resolve */);
        read_ListFilesRequest(&request, rroot);

        if (!request.hasPath) {
            request.path = chars_to_text("/");
        }

        directory = ms_io_opendir(request.path.str);
        ms_printf("Listing directory: %s\n", request.path.str);
        strcpy(abs_path, request.path.str);
        p_path_name = &abs_path[strlen(abs_path)];
    }

    /* List the files in the directory and transmit the response to client */
    {
        struct capn c;
        capn_init_malloc(&c);
        capn_ptr cr = capn_root(&c);
        struct capn_segment *cs = cr.seg;
        struct ListFilesResponse response;

        if (directory == NULL) {
            /* Directory was not found, transmit error status */
            response.hasError = 1;
        } else {
            /* Directory was found, transmit filenames */
            response.hasError = 0;
        }

        int i = 0;
        ms_dirent_t dirent;
        ms_dirent_t *res;
        struct ListFilesResponse_FileInfo fileinfo;
        ms_stat_t st;

        i = 0;
        while (ms_io_readdir_r(directory, &dirent, &res) == 0 && res) {
            i++;
        }
        ms_io_rewinddir(directory);
        response.files = new_ListFilesResponse_FileInfo_list(cs, i);

        i = 0;
        while (ms_io_readdir_r(directory, &dirent, &res) == 0 && res) {
            sprintf(p_path_name, "/%s", dirent.d_name);
            if (ms_io_stat(abs_path, &st) < 0) {
                ms_printf("Failed to stat %s!\n", abs_path);
                st.st_size = 0;
            }
            fileinfo.inode = st.st_size;
            fileinfo.name  = chars_to_text(dirent.d_name);
            set_ListFilesResponse_FileInfo(&fileinfo, response.files, i++);
        }

        ListFilesResponse_ptr rp = new_ListFilesResponse(cs);
        write_ListFilesResponse(&response, rp);
        int setp_ret = capn_setp(capn_root(&c), 0, rp.p);
        if (setp_ret != 0) {
            ms_printf("capn_setp() failed!\n");
            abort();
        }
        sz = capn_write_mem(&c, buf, sizeof(buf), 0 /* packed */);
        capn_free(&c);

        /* Encode the response. It is written to the socket immediately
         * through our custom stream. */
        if (ms_io_write(write_fd, buf, sz) != sz) {
            ms_printf("ms_io_write ListFilesResponse failed!\n");
            abort();
        }
    }

    if (directory != NULL) {
        ms_io_closedir(directory);
    }
}

int main (int argc, char **argv)
{
    int read_fd, write_fd;

    ms_printf("Hello capnp-server!\n");

    if (ms_pipe_dev_create("/dev/pipe0", 256) < 0) {
        ms_printf("failed to create pipe\n");
        abort();
    }

    if (ms_pipe_dev_create("/dev/pipe1", 1024) < 0) {
        ms_printf("failed to create pipe\n");
        abort();
    }

    read_fd  = ms_io_open("/dev/pipe0", O_RDONLY, 0666);
    write_fd = ms_io_open("/dev/pipe1", O_WRONLY, 0666);

    handle_connection(read_fd, write_fd);

    ms_io_close(read_fd);
    ms_io_close(write_fd);

    return  (0);
}
