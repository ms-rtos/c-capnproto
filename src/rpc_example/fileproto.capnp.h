#ifndef CAPN_9EB32E19F86EE174
#define CAPN_9EB32E19F86EE174
/* AUTO GENERATED - DO NOT EDIT */
#include <capnp_c.h>

#if CAPN_VERSION != 1
#error "version mismatch between capnp_c.h and generated code"
#endif

#ifndef capnp_nowarn
# ifdef __GNUC__
#  define capnp_nowarn __extension__
# else
#  define capnp_nowarn
# endif
#endif

#include "./c.capnp.h"

#ifdef __cplusplus
extern "C" {
#endif

struct ListFilesRequest;
struct ListFilesResponse;
struct ListFilesResponse_FileInfo;

typedef struct {capn_ptr p;} ListFilesRequest_ptr;
typedef struct {capn_ptr p;} ListFilesResponse_ptr;
typedef struct {capn_ptr p;} ListFilesResponse_FileInfo_ptr;

typedef struct {capn_ptr p;} ListFilesRequest_list;
typedef struct {capn_ptr p;} ListFilesResponse_list;
typedef struct {capn_ptr p;} ListFilesResponse_FileInfo_list;

struct ListFilesRequest {
	unsigned hasPath : 1;
	capn_text path;
};

static const size_t ListFilesRequest_word_count = 1;

static const size_t ListFilesRequest_pointer_count = 1;

static const size_t ListFilesRequest_struct_bytes_count = 16;

unsigned ListFilesRequest_get_hasPath(ListFilesRequest_ptr p);

capn_text ListFilesRequest_get_path(ListFilesRequest_ptr p);

void ListFilesRequest_set_hasPath(ListFilesRequest_ptr p, unsigned hasPath);

void ListFilesRequest_set_path(ListFilesRequest_ptr p, capn_text path);

struct ListFilesResponse {
	unsigned hasError : 1;
	ListFilesResponse_FileInfo_list files;
};

static const size_t ListFilesResponse_word_count = 1;

static const size_t ListFilesResponse_pointer_count = 1;

static const size_t ListFilesResponse_struct_bytes_count = 16;

unsigned ListFilesResponse_get_hasError(ListFilesResponse_ptr p);

ListFilesResponse_FileInfo_list ListFilesResponse_get_files(ListFilesResponse_ptr p);

void ListFilesResponse_set_hasError(ListFilesResponse_ptr p, unsigned hasError);

void ListFilesResponse_set_files(ListFilesResponse_ptr p, ListFilesResponse_FileInfo_list files);

struct ListFilesResponse_FileInfo {
	uint64_t inode;
	capn_text name;
};

static const size_t ListFilesResponse_FileInfo_word_count = 1;

static const size_t ListFilesResponse_FileInfo_pointer_count = 1;

static const size_t ListFilesResponse_FileInfo_struct_bytes_count = 16;

uint64_t ListFilesResponse_FileInfo_get_inode(ListFilesResponse_FileInfo_ptr p);

capn_text ListFilesResponse_FileInfo_get_name(ListFilesResponse_FileInfo_ptr p);

void ListFilesResponse_FileInfo_set_inode(ListFilesResponse_FileInfo_ptr p, uint64_t inode);

void ListFilesResponse_FileInfo_set_name(ListFilesResponse_FileInfo_ptr p, capn_text name);

ListFilesRequest_ptr new_ListFilesRequest(struct capn_segment*);
ListFilesResponse_ptr new_ListFilesResponse(struct capn_segment*);
ListFilesResponse_FileInfo_ptr new_ListFilesResponse_FileInfo(struct capn_segment*);

ListFilesRequest_list new_ListFilesRequest_list(struct capn_segment*, int len);
ListFilesResponse_list new_ListFilesResponse_list(struct capn_segment*, int len);
ListFilesResponse_FileInfo_list new_ListFilesResponse_FileInfo_list(struct capn_segment*, int len);

void read_ListFilesRequest(struct ListFilesRequest*, ListFilesRequest_ptr);
void read_ListFilesResponse(struct ListFilesResponse*, ListFilesResponse_ptr);
void read_ListFilesResponse_FileInfo(struct ListFilesResponse_FileInfo*, ListFilesResponse_FileInfo_ptr);

void write_ListFilesRequest(const struct ListFilesRequest*, ListFilesRequest_ptr);
void write_ListFilesResponse(const struct ListFilesResponse*, ListFilesResponse_ptr);
void write_ListFilesResponse_FileInfo(const struct ListFilesResponse_FileInfo*, ListFilesResponse_FileInfo_ptr);

void get_ListFilesRequest(struct ListFilesRequest*, ListFilesRequest_list, int i);
void get_ListFilesResponse(struct ListFilesResponse*, ListFilesResponse_list, int i);
void get_ListFilesResponse_FileInfo(struct ListFilesResponse_FileInfo*, ListFilesResponse_FileInfo_list, int i);

void set_ListFilesRequest(const struct ListFilesRequest*, ListFilesRequest_list, int i);
void set_ListFilesResponse(const struct ListFilesResponse*, ListFilesResponse_list, int i);
void set_ListFilesResponse_FileInfo(const struct ListFilesResponse_FileInfo*, ListFilesResponse_FileInfo_list, int i);

#ifdef __cplusplus
}
#endif
#endif
