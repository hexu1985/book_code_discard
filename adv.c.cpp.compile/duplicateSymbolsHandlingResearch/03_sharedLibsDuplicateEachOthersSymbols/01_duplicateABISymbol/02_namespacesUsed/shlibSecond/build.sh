g++ -Wall -g -O0 -c shlib.c 
g++ -shared shlib.o -Wl,-soname,libsecond.so.1 -o libsecond.so.1.0.0

