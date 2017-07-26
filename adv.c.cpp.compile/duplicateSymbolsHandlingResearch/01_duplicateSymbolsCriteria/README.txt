
As expected, the presence of duplicate symbols in
two or more static libraries is not tolerated. The
build procedure which tries to link these libraries
together will declare the failure.

However, the presence of duplicates in two or more
dynamic libraries will be tolerated. It will be left
to the linker algorithm to favor one or the other
instance of duplicated symbol.

As expected, C++ compiler is far more tolerant in 
terms of what is qualified as the duplicate symbol.
Even when the functions are not affiliated to any
of the classes, it is acceptable that they have the
same name as long as:
 - the return value type is the same
 - the list of input arguments differ
 
The C compiler, however, is far less tolerant, as
it does not allow the function names to be equal,
regardless of anything else.

