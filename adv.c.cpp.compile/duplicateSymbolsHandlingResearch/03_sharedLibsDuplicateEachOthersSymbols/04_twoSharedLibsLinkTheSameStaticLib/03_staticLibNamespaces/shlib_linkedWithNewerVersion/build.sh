g++ -Wall -g -O0 -I../staticLib_newerVersion -c shlib.c extra_shlib_stuff.c
g++ -shared shlib.o extra_shlib_stuff.o \
    -L../staticLib_newerVersion -lstaticlib \
    -Wl,-soname,libshlibnewer.so.1 -o libshlibnewer.so.1.0.0

