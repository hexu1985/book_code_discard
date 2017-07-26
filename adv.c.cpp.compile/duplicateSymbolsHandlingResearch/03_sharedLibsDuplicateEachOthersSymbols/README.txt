
Illustrating of how the loader (i.e. dynamic linker) 
handles the duplicate symbols:

1) Even though the two shared libraries expose the ABI
   functions of the exactly same signature, the loader 
   picks the first one it finds and ignores the other. 
   The order of linking matters, as the first library 
   passed to the linker first gets examined for symbols. 
   The order of function calls in the code does not affect 
   the order of linking.
   
   The deviation from this rule may happen when one ABI
   function calls another ABI function of the same shlib. 
   In that case the expected function gets called, and 
   the duplication issue does not come to play.
   
2) If a shared library local symbol duplicates another
   shared library exported (ABI) symbol, these two symbols
   are essentially non-competing and there is never a 
   chance that one of the symbols will be overriden.
   
   It seems that the loader makes clear distinction between
   the ABI symbols (belonging to the dynamic symbols section)
   and the local shared lib symbols.
   
   No namespacing is strictly required, as the resolution
   of the symbols passes without the problem.

3) If shared libraries have duplicate symbols which are both
   local, the loader picks the first one it finds and 
   ignores the other. The order of linking matters, as
   the first library passed to the linker first gets
   examined for symbols. The order of function calls in
   the code does not affect the order of linking.
   
   The loader fortunately observes the namespaces. Using
   the namespaces uniquely identifies the library symbols
   and helps avoiding the duplicate symbols issues.
   
   The sub-case happens when the two shared libraries
   link in the same static library (albeit of possibly two
   different minor versions). The loader handles this 
   scenario under the same principles. 
   
   The only detail worth of mentioning is that the following
   misconception should be dispelled: 
   
    when namespaced shared lib links in (un-namespaced) 
    static lib, the methods of the static lib do NOT get 
    encapsulated into the shared lib namespaces. 
    If you want to really protect your static library's
    symbols uniqueness, set the static library namespace
    explicitly (i.e. do not count on client binary's 
    namespaces to solve the problem).
    
    More general statement is: linking does not pack symbols 
    into the client binary namespaces.

4) this priority scheme is irrelevant in the cases when the
   dynamic library is dynamically loaded at run time by using
   the dlopen() call. In that particular case, all the referenced
   symbols are extracted from the loaded library at run time,
   at which occasion the linker's schemes do not come to play 
   any role.
