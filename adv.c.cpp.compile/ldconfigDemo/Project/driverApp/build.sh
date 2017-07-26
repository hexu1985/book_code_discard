gcc -Wall -g -O0 -c -I../sharedLib main.c 
#gcc main.o -Wl,-L../sharedLib -lshlibdemo -Wl,-R../sharedLib -o demo 
gcc main.o -Wl,-L../sharedLib -lshlibdemo -o demo 
