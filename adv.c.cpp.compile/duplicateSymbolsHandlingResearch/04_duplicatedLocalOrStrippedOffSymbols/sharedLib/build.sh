gcc -Wall -g -O0 -I../staticLib -c shlib.c 
gcc -shared shlib.o -Wl,-soname,libshlib.so.1 -o libshlib.so.1.0.0
strip -N local_function_strippedoff libshlib.so.1.0.0
ldconfig -n .
ln -s libshlib.so.1 libshlib.so


