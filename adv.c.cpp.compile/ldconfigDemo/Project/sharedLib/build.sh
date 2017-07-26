gcc -Wall -g -O0 -fPIC -c shlibdemo.c
gcc -shared shlibdemo.o -Wl,-soname,libshlibdemo.so.1 -o libshlibdemo.so.1.0.0
