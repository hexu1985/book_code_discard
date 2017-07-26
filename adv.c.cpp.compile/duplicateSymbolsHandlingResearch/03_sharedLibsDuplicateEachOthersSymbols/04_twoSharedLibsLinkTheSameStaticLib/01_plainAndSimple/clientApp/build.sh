gcc -Wall -g -O0 -I../shlib_linkedWithOriginalVersion \
                 -I../shlib_linkedWithNewerVersion    \
                 -c main.c
gcc main.o -Wl,-L../shlib_linkedWithOriginalVersion   \
           -Wl,-L../shlib_linkedWithNewerVersion      \
           -Wl,-lshliboriginal                        \
           -Wl,-lshlibnewer                           \
           -Wl,-R../shlib_linkedWithOriginalVersion   \
           -Wl,-R../shlib_linkedWithNewerVersion      \
           -o clientApp
