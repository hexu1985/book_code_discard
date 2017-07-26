gcc -Wall -g -O0 -fPIC -I../sharedLib1 -c shlibdemo.c
gcc -shared -Wl,--no-undefined shlibdemo.o -L../sharedLib1 -ldependencyshlib -o libshlibdemo.so
