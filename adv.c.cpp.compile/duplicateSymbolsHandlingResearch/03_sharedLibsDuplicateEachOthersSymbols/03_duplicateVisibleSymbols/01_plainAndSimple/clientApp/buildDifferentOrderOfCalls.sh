gcc -Wall -g -O0 -I../shlibFirst -I../shlibSecond -c main_differentOrderOfCalls.c
gcc main_differentOrderOfCalls.o         \
           -Wl,-L../shlibFirst  -lfirst  \
           -Wl,-L../shlibSecond -lsecond \
           -Wl,-R../shlibFirst           \
           -Wl,-R../shlibSecond          \
           -o clientAppDifferentOrderOfCalls
