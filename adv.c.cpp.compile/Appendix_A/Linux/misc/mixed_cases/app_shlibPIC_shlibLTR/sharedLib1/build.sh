gcc -Wall -g -O0 -c dependencyShlib.c
gcc -shared dependencyShlib.o -o libdependencyshlib.so
