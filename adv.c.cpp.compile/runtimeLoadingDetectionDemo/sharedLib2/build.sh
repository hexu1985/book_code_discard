gcc -g -O0 -I./export -c sharedLib2Functions.c
gcc -shared sharedLib2Functions.o -o libdemo2.so
