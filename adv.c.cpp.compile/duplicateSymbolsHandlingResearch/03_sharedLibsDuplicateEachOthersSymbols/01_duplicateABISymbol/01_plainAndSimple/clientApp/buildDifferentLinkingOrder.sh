gcc -Wall -g -O0 -I../shlibFirst -I../shlibSecond -c main.c
gcc main.o -Wl,-L../shlibSecond -lsecond \
           -Wl,-L../shlibFirst  -lfirst  \
           -Wl,-R../shlibFirst           \
           -Wl,-R../shlibSecond          \
           -o clientAppDifferentLinkingOrder
