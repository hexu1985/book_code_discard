The following code examples demonstrate a few simple facts
related to the scenario 1:

1) The client binary (app in this case) obtains the 
rel.plt section only if the app statically aware links 
a dynamic library. 

2) From the caller's standpoint it does not matter whether
the dynamic library is built as PIC or as LTR. The caller
is interested strictly in resolving the location of the call.

3) The demo program located at 
   01_appCallingShlib/01_functionSymbols/PIC
is the most useful demo. All the other cases are made for
comparison purposes only.

4) Dealing with the data exported by the dynamic library does
not happen through the specific sections. In order to access
the data located in a shared library, the client binary must
mark is as 'extern', in which case the linker reserves the
place in the client binary's .bss or .data field, and the 
dynamic library data gets mapped to it.
