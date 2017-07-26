gcc -Wall -g -O0 -I../libFirst -I../libSecond -c main.c
gcc main.o -L../libFirst -lfirst -L../libSecond -lsecond -o clientApp
