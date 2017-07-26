These examples illustrates several important points:

1) How to create Makefile for shared library project
2) How to create Makefile for test app project
3) How to create top level Makefile

4) How to support DEBUG=0 or DEBUG=1 flag from the top level Makefile
   To test it, run from command line either
      make DEBUG=0
   or
      make DEBUG=1

5) What happens with the symbols when app links statically aware with
   the shared library (please examine the Notes folder)
   
6) How to use patchelf utility to turn the executable's existing rpath
   to a new multi-path rpath
   
7) How to build a static library (ar rcs <outputlib> <objectfiles>)
