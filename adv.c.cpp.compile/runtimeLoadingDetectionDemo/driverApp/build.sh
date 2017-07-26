gcc -g -O0 -c -I../sharedLib1/export -I../sharedLib2/export main.c
gcc main.o -ldl -Wl,-L../sharedLib1 -ldemo1 -Wl,-R../sharedLib1 -Wl,-R../sharedLib2 -o driverApp
