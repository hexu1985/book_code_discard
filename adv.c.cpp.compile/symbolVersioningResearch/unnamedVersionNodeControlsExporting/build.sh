gcc -Wall -fPIC -c scriptVisibilityControl.c
gcc -shared scriptVisibilityControl.o \
    -Wl,--version-script,exportControlScript \
    -o libscriptcontrolsexportdemo.so
