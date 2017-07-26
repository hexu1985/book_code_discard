gcc -g -O0 -c -DSIMPLELIB_VERSION_3_0 -I../sharedLib main.c
gcc main.o -Wl,-L../sharedLib -lsimple \
           -Wl,-R../sharedLib -o ver3PeerApp 
