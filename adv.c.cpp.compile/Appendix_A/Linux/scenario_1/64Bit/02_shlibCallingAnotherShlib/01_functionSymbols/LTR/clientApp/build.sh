gcc -Wall -g -O0 -I../shlibFirst -c main.c
gcc main.o -L../shlibFirst -lfirst -Wl,-R../shlibFirst -o clientApp
