gcc -Wall -g -O0 -I../libFirst -I../libSecond -c main.c
gcc main.o -Wl,-L../libFirst -Wl,-lfirst   \
           -Wl,-R../libFirst               \
           -ldl                            \
           -o clientApp
