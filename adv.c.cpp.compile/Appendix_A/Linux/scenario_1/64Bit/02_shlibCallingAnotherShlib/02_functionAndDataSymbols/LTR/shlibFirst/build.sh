rm -rf *.o lib*
gcc -Wall -g -O0 -I../shlibSecond -mcmodel=large -c shlib.c
gcc -shared shlib.o -L../shlibSecond -lsecond -Wl,-R../shlibSecond \
    -Wl,-soname,libfirst.so.1 -o libfirst.so.1.0.0
ldconfig -l libfirst.so.1.0.0
ln -s libfirst.so.1 libfirst.so
