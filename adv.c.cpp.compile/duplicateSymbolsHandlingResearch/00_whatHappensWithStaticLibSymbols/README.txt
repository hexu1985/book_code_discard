

The purpose of this simple experiment 
is to provide the precise insight as to
what exactly happens with the static 
library symbols when the static library 
gets linked to either application or a 
shared library.

In general, these examples describe primarily
how the LINKER, i.e. not the loader (dynamic
linker) handles the static library symbols.

Several scenarios exist:

1) DIRECT LINKING of STATIC LIB

When application or a shared library links
in the static library, the static library
symbols do not loose any of its visibility
in the newly created module.

- when declared 'static', the static lib
  symbols continue being static/unexported
  in any binary which linked in the static
  library

- when not declared 'static', whether they
  are declared in the export header file 
  or not, the static library symbols become
  fully visible/exported from the binary
  which linked the static library.
  
- not the whole static library gets linked
  in. Only of its archived object files 
  which contain the required symbols get 
  pulled in. All the other object files do
  not get pulled in.
  
2) INDIRECT LINKING of STATIC LIB (i.e. 
   THROUGH THE SHARED LIBRARY)
   
  Of all the shared library *symbols* only
  the needed symbols get added to the client
  binary. 
  
  However, at run time the complete shared
  library code gets pulled in.
  
  
