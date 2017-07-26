gcc -Wall -g -O0 -fPIC -c dependencyShlib.c
gcc -shared dependencyShlib.o -o libdependencyshlib.so
