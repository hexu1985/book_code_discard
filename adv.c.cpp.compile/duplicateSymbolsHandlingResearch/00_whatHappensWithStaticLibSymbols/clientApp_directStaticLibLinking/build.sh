gcc -Wall -g -O0 -I../staticLib -c main.c
gcc main.o -L../staticLib -lstaticlib -o clientApp
