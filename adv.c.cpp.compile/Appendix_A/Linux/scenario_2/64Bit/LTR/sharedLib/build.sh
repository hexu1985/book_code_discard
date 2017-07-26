rm -rf *.o lib*
gcc -Wall -g -O0 -mcmodel=large -c shlib.c
gcc -shared shlib.o -o libshlib.so.1.0.0 -Wl,-soname,libshlib.so.1
ldconfig -l libshlib.so.1.0.0
ln -s libshlib.so.1 libshlib.so

