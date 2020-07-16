/*
 * Copyright (c) 2015-2020 ACOINFO Co., Ltd.
 * All rights reserved.
 *
 * Detailed license information can be found in the LICENSE file.
 *
 * File: capnp_client.c c-capnproto client.
 *
 * Author: Jiao.jinxing <jiaojinxing@acoinfo.com>
 *
 */

#include <ms_rtos.h>
#include <stdlib.h>
#include <string.h>

#include "capnp_c.h"
#include "fileproto.capnp.h"

static capn_text chars_to_text(const char *chars)
{
    return  (capn_text) {.len = (int) strlen(chars),
                         .str = chars,
                         .seg = NULL,
                        };
}

/* This function sends a request to pipe 'fd' to list the files in
 * directory given in 'path'. The results received from server will
 * be printed to stdout.
 */
ms_bool_t listdir(int write_fd, int read_fd, char *path)
{
    static ms_uint8_t buf[4096];
    ms_ssize_t sz = 0;

    /* Construct and send the request to server */
    {
        struct capn c;
        capn_init_malloc(&c);
        capn_ptr cr = capn_root(&c);
        struct capn_segment *cs = cr.seg;

        struct ListFilesRequest  request;

        /* In our protocol, path is optional. If it is not given,
         * the server will list the root directory. */
        if (path == NULL) {
            request.hasPath = 0;
        } else {
            request.hasPath = 1;
            request.path    = chars_to_text(path);
        }

        ListFilesRequest_ptr rp = new_ListFilesRequest(cs);
        write_ListFilesRequest(&request, rp);
        int setp_ret = capn_setp(capn_root(&c), 0, rp.p);
        if (setp_ret != 0) {
            ms_printf("capn_setp() failed!\n");
            abort();
        }
        sz = capn_write_mem(&c, buf, sizeof(buf), 0 /* packed */);
        capn_free(&c);

        /* Encode the request. It is written to the socket immediately
         * through our custom stream. */
        if (ms_io_write(write_fd, buf, sz) != sz) {
            ms_printf("ms_io_write ListFilesRequest failed!\n");
            abort();
        }
    }

    /* Read back the response from server */
    {
        /* Deserialize `buf[0..sz-1]` to `rp`. */
        struct capn rc;
        int init_mem_ret;
        ListFilesResponse_ptr rroot;
        struct ListFilesResponse rp;
        int files_num;
        int i;

        sz = ms_io_read(read_fd, buf, 4096);
        if (sz <= 0) {
            ms_printf("ms_io_read() read ListFilesResponse failed!\n");
            abort();
        }

        init_mem_ret = capn_init_mem(&rc, buf, sz, 0 /* packed */);
        if (init_mem_ret != 0) {
            ms_printf("capn_init_mem() failed!\n");
            abort();
        }

        rroot.p = capn_getp(capn_root(&rc), 0 /* off */, 1 /* resolve */);
        read_ListFilesResponse(&rp, rroot);

        /* If the message from server decodes properly, but directory was
         * not found on server side, we get hasError == true. */
        if (rp.hasError) {
            ms_printf("Server reported error.\n");
            return MS_FALSE;
        }

        files_num = capn_len(rp.files);

        struct ListFilesResponse_FileInfo fileinfo;
        for (i =0; i < files_num; i++) {
            get_ListFilesResponse_FileInfo(&fileinfo, rp.files, i);

            ms_printf("%-10lld %s\n", (long long)fileinfo.inode, fileinfo.name.str);
        }
    }

    return MS_TRUE;
}

int main (int argc, char **argv)
{
    int write_fd, read_fd;
    char *path = "/nor/app_db";

    ms_printf("Hello capnp-client!\n");

    write_fd = ms_io_open("/dev/pipe0", O_WRONLY, 0666);
    read_fd  = ms_io_open("/dev/pipe1", O_RDONLY, 0666);

    /* Send the directory listing request */
    if (!listdir(write_fd, read_fd, path))
        return 2;

    /* Close connection */
    ms_io_close(write_fd);
    ms_io_close(read_fd);

    return  (0);
}
