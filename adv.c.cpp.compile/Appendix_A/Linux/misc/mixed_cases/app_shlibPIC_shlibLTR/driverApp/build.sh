gcc -Wall -g -O0 -c -I../sharedLib main.c 
gcc main.o -Wl,-L../sharedLib -lshlibdemo -Wl,-R../sharedLib -Wl,-R../sharedLib1 -o demo 
