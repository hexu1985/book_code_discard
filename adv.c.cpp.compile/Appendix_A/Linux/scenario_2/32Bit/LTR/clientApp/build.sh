gcc -Wall -g -O0 -c -I../sharedLib main.c 
gcc main.o -Wl,-L../sharedLib -lshlib -Wl,-R../sharedLib -o clientApp
