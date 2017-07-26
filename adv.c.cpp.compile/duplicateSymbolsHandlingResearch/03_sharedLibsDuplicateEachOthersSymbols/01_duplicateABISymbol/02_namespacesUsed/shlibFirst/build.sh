g++ -Wall -g -O0 -c shlib.c 
g++ -shared shlib.o -Wl,-soname,libfirst.so.1 -o libfirst.so.1.0.0

