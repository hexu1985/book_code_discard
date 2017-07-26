gcc -Wall -g -O0 -I../staticLib -I../sharedLib -c main.c
gcc main.o -Wl,-L../sharedLib -lshlib     \
           -Wl,-L../staticLib -lstaticlib \
           -Wl,-R../sharedLib             \
           -o clientAppDifferentLinkingOrder
