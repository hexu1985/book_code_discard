g++ -Wall -g -O0 -I../shlibFirst -I../shlibSecond -c main.c
g++ main.o -Wl,-L../shlibFirst -lfirst   \
           -Wl,-L../shlibSecond -lsecond \
           -Wl,-R../shlibFirst           \
           -Wl,-R../shlibSecond          \
           -o clientApp
