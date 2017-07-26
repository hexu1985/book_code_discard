gcc -Wall -g -O0 -fPIC -c shlib.c
gcc -shared shlib.o -Wl,-soname,libsecond.so.1 -o libsecond.so.1.0.0
ldconfig -n .
ln -s libsecond.so.1 libsecond.so

