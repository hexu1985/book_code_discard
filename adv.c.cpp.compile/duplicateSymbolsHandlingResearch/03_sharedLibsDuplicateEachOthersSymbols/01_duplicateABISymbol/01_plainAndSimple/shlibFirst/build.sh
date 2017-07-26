gcc -Wall -g -O0 -c shlib.c 
gcc -shared shlib.o -Wl,-soname,libfirst.so.1 -o libfirst.so.1.0.0

