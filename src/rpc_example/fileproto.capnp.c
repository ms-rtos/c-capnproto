#include "fileproto.capnp.h"
/* AUTO GENERATED - DO NOT EDIT */
#ifdef __GNUC__
# define capnp_unused __attribute__((unused))
# define capnp_use(x) (void) x;
#else
# define capnp_unused
# define capnp_use(x)
#endif

static const capn_text capn_val0 = {0,"",0};

ListFilesRequest_ptr new_ListFilesRequest(struct capn_segment *s) {
	ListFilesRequest_ptr p;
	p.p = capn_new_struct(s, 8, 1);
	return p;
}
ListFilesRequest_list new_ListFilesRequest_list(struct capn_segment *s, int len) {
	ListFilesRequest_list p;
	p.p = capn_new_list(s, len, 8, 1);
	return p;
}
void read_ListFilesRequest(struct ListFilesRequest *s capnp_unused, ListFilesRequest_ptr p) {
	capn_resolve(&p.p);
	capnp_use(s);
	s->hasPath = (capn_read8(p.p, 0) & 1) != 0;
	s->path = capn_get_text(p.p, 0, capn_val0);
}
void write_ListFilesRequest(const struct ListFilesRequest *s capnp_unused, ListFilesRequest_ptr p) {
	capn_resolve(&p.p);
	capnp_use(s);
	capn_write1(p.p, 0, s->hasPath != 0);
	capn_set_text(p.p, 0, s->path);
}
void get_ListFilesRequest(struct ListFilesRequest *s, ListFilesRequest_list l, int i) {
	ListFilesRequest_ptr p;
	p.p = capn_getp(l.p, i, 0);
	read_ListFilesRequest(s, p);
}
void set_ListFilesRequest(const struct ListFilesRequest *s, ListFilesRequest_list l, int i) {
	ListFilesRequest_ptr p;
	p.p = capn_getp(l.p, i, 0);
	write_ListFilesRequest(s, p);
}

unsigned ListFilesRequest_get_hasPath(ListFilesRequest_ptr p)
{
	unsigned hasPath;
	hasPath = (capn_read8(p.p, 0) & 1) != 0;
	return hasPath;
}

capn_text ListFilesRequest_get_path(ListFilesRequest_ptr p)
{
	capn_text path;
	path = capn_get_text(p.p, 0, capn_val0);
	return path;
}

void ListFilesRequest_set_hasPath(ListFilesRequest_ptr p, unsigned hasPath)
{
	capn_write1(p.p, 0, hasPath != 0);
}

void ListFilesRequest_set_path(ListFilesRequest_ptr p, capn_text path)
{
	capn_set_text(p.p, 0, path);
}

ListFilesResponse_ptr new_ListFilesResponse(struct capn_segment *s) {
	ListFilesResponse_ptr p;
	p.p = capn_new_struct(s, 8, 1);
	return p;
}
ListFilesResponse_list new_ListFilesResponse_list(struct capn_segment *s, int len) {
	ListFilesResponse_list p;
	p.p = capn_new_list(s, len, 8, 1);
	return p;
}
void read_ListFilesResponse(struct ListFilesResponse *s capnp_unused, ListFilesResponse_ptr p) {
	capn_resolve(&p.p);
	capnp_use(s);
	s->hasError = (capn_read8(p.p, 0) & 1) != 0;
	s->files.p = capn_getp(p.p, 0, 0);
}
void write_ListFilesResponse(const struct ListFilesResponse *s capnp_unused, ListFilesResponse_ptr p) {
	capn_resolve(&p.p);
	capnp_use(s);
	capn_write1(p.p, 0, s->hasError != 0);
	capn_setp(p.p, 0, s->files.p);
}
void get_ListFilesResponse(struct ListFilesResponse *s, ListFilesResponse_list l, int i) {
	ListFilesResponse_ptr p;
	p.p = capn_getp(l.p, i, 0);
	read_ListFilesResponse(s, p);
}
void set_ListFilesResponse(const struct ListFilesResponse *s, ListFilesResponse_list l, int i) {
	ListFilesResponse_ptr p;
	p.p = capn_getp(l.p, i, 0);
	write_ListFilesResponse(s, p);
}

unsigned ListFilesResponse_get_hasError(ListFilesResponse_ptr p)
{
	unsigned hasError;
	hasError = (capn_read8(p.p, 0) & 1) != 0;
	return hasError;
}

ListFilesResponse_FileInfo_list ListFilesResponse_get_files(ListFilesResponse_ptr p)
{
	ListFilesResponse_FileInfo_list files;
	files.p = capn_getp(p.p, 0, 0);
	return files;
}

void ListFilesResponse_set_hasError(ListFilesResponse_ptr p, unsigned hasError)
{
	capn_write1(p.p, 0, hasError != 0);
}

void ListFilesResponse_set_files(ListFilesResponse_ptr p, ListFilesResponse_FileInfo_list files)
{
	capn_setp(p.p, 0, files.p);
}

ListFilesResponse_FileInfo_ptr new_ListFilesResponse_FileInfo(struct capn_segment *s) {
	ListFilesResponse_FileInfo_ptr p;
	p.p = capn_new_struct(s, 8, 1);
	return p;
}
ListFilesResponse_FileInfo_list new_ListFilesResponse_FileInfo_list(struct capn_segment *s, int len) {
	ListFilesResponse_FileInfo_list p;
	p.p = capn_new_list(s, len, 8, 1);
	return p;
}
void read_ListFilesResponse_FileInfo(struct ListFilesResponse_FileInfo *s capnp_unused, ListFilesResponse_FileInfo_ptr p) {
	capn_resolve(&p.p);
	capnp_use(s);
	s->inode = capn_read64(p.p, 0);
	s->name = capn_get_text(p.p, 0, capn_val0);
}
void write_ListFilesResponse_FileInfo(const struct ListFilesResponse_FileInfo *s capnp_unused, ListFilesResponse_FileInfo_ptr p) {
	capn_resolve(&p.p);
	capnp_use(s);
	capn_write64(p.p, 0, s->inode);
	capn_set_text(p.p, 0, s->name);
}
void get_ListFilesResponse_FileInfo(struct ListFilesResponse_FileInfo *s, ListFilesResponse_FileInfo_list l, int i) {
	ListFilesResponse_FileInfo_ptr p;
	p.p = capn_getp(l.p, i, 0);
	read_ListFilesResponse_FileInfo(s, p);
}
void set_ListFilesResponse_FileInfo(const struct ListFilesResponse_FileInfo *s, ListFilesResponse_FileInfo_list l, int i) {
	ListFilesResponse_FileInfo_ptr p;
	p.p = capn_getp(l.p, i, 0);
	write_ListFilesResponse_FileInfo(s, p);
}

uint64_t ListFilesResponse_FileInfo_get_inode(ListFilesResponse_FileInfo_ptr p)
{
	uint64_t inode;
	inode = capn_read64(p.p, 0);
	return inode;
}

capn_text ListFilesResponse_FileInfo_get_name(ListFilesResponse_FileInfo_ptr p)
{
	capn_text name;
	name = capn_get_text(p.p, 0, capn_val0);
	return name;
}

void ListFilesResponse_FileInfo_set_inode(ListFilesResponse_FileInfo_ptr p, uint64_t inode)
{
	capn_write64(p.p, 0, inode);
}

void ListFilesResponse_FileInfo_set_name(ListFilesResponse_FileInfo_ptr p, capn_text name)
{
	capn_set_text(p.p, 0, name);
}
