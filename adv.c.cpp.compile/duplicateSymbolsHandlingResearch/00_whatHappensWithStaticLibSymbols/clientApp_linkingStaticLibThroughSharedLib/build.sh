gcc -Wall -g -O0 -I../clientShlib -c main.c
gcc main.o -Wl,-L../clientShlib -Wl,-lshlib -Wl,-R../clientShlib -o clientApp
