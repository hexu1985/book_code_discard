g++ -Wall -g -O0 -I../staticLib -I../shlibFirst -I../shlibSecond -c main.cpp
g++ main.o -ldl -L../staticLib -lsingleton \
                -L../shlibFirst -lfirst    \
                -L../shlibSecond -lsecond  \
                -Wl,-R../shlibFirst        \
                -Wl,-R../shlibSecond       \
                -o clientApp
