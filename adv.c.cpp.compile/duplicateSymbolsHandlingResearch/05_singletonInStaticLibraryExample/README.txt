
The following two cases demonstrate that
a) the problem of singleton implemented in static library
   definitely exists. The problem is confined to the case
   when singleton is implemented not by using the named
   mutex but instead by using the private class static 
   instance member.

b) the root of the problem is completely unrelated to the
   way of how the dynamic linking is performed.

c) the problem appears only when the static library symbols
   are not exported (or stripped), in which case the singleton
   symbol becomes private property of the dynamic library. 
   As we know already, the local/stripped off symbols are
   completely private to the library and are non-competing
   accross the dynamic libraries boundaries. Hence it is
   possible to have multiple instances of supposed singleton. 
