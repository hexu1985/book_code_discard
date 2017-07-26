#!/bin/sh

ls -1 *.cpp | \
while read srcfile
do
    echo "now compile $srcfile..."
    target=${srcfile%.cpp}.exe
    g++ -I../include -o ${target} ${srcfile}
done

