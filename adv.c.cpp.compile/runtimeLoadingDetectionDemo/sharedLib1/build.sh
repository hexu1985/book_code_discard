gcc -g -O0 -I./export -c sharedLib1Functions.c
gcc -shared sharedLib1Functions.o -o libdemo1.so
