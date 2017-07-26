gcc -Wall -g -O0 -I../libFirst -I../libSecond -c main.c
gcc main.o -Wl,-L../libFirst -Wl,-lfirst   \
           -Wl,-L../libSecond -Wl,-lsecond \
           -Wl,-R../libFirst               \
           -Wl,-R../libSecond              \
           -o clientApp
