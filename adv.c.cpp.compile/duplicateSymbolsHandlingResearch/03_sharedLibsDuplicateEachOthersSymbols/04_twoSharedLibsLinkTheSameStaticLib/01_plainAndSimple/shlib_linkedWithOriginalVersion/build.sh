gcc -Wall -g -O0 -I../staticLib_originalVersion -c shlib.c extra_shlib_stuff.c
gcc -shared shlib.o extra_shlib_stuff.o \
    -L../staticLib_originalVersion -lstaticlib \
    -Wl,-soname,libshliboriginal.so.1 -o libshliboriginal.so.1.0.0

