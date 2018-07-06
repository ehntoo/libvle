all: libvle.a libvle.so
	@echo "libvle.a and libvle.so built!"

libvle.a: vle.o
	ar rcs libvle.a vle.o

vle.o: vle.h vle_internal.h
	gcc -c -fPIC -Wall -Wextra -o vle.o vle.c

libvle.so: vle.o
	gcc vle.o -shared -o libvle.so

test-chain: libvle.a
	gcc -o test test.c libvle.a

clean:
	rm -rf *.o test *.a
