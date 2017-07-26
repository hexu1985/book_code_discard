g++ -Wall -g -O0 -I../shlib_linkedWithOriginalVersion \
                 -I../shlib_linkedWithNewerVersion    \
                 -c main.c
g++ main.o -Wl,-L../shlib_linkedWithOriginalVersion   \
           -Wl,-L../shlib_linkedWithNewerVersion      \
           -Wl,-lshlibnewer                           \
           -Wl,-lshliboriginal                        \
           -Wl,-R../shlib_linkedWithOriginalVersion   \
           -Wl,-R../shlib_linkedWithNewerVersion      \
           -o clientAppDifferentLinkingOrder
