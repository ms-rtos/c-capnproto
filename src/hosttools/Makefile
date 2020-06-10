
all:
	gcc -c ../c-capnproto/lib/capn.c -o capn.o -I"../c-capnproto/lib"
	gcc -c ../c-capnproto/lib/capn-malloc.c -o capn-malloc.o -I"../c-capnproto/lib"
	gcc -c ../c-capnproto/lib/capn-stream.c -o capn-stream.o -I"../c-capnproto/lib"
	gcc -c ../c-capnproto/compiler/capnpc-c.c -o capnpc-c.o -I"../c-capnproto/lib"
	gcc -c ../c-capnproto/compiler/schema.capnp.c -o schema.capnp.o -I"../c-capnproto/lib"
	gcc -c ../c-capnproto/compiler/str.c -o str.o -I"../c-capnproto/lib"
	gcc *.o -o capnpc-c.exe
	rm *.o