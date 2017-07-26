
These examples illustrate the limitations
of the loader (dynamic linker) in handling
the duplicate symbols.

In this particular example, the client app
is built by linking in the static library
as well as the shared library, both of which
have one symbol in common.

As the examples show, the static library
symbol always gets picked first, no matter
of what is the linking order. 

It shows that the loader never tries to
override what linker already did. In the
case of linking the static library, the
linker already resolved the symbols. The
dynamic linking of shared library comes
after the fact, and there is nothing that
loader feels urged to do when encountering
the duplicate symbol.


