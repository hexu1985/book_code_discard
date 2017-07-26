gcc -Wall -g -O0 -I../staticLib -c shlib.c extra_shlib_stuff.c
gcc -shared shlib.o extra_shlib_stuff.o -L../staticLib -lstaticlib -Wl,-soname,libshlib.so.1 -o libshlib.so.1.0.0

