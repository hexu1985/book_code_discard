gcc -Wall -g -O0 -fPIC -I../shlibSecond -c shlib.c
gcc -shared shlib.o -L../shlibSecond -lsecond -Wl,-R../shlibSecond \
    -Wl,-soname,libfirst.so.1 -o libfirst.so.1.0.0
