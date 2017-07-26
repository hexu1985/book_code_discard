gcc -Wall -g -O0 -c staticlib.c extra_staticlib_functions.c
ar -rcs libstaticlib.a staticlib.o extra_staticlib_functions.o

