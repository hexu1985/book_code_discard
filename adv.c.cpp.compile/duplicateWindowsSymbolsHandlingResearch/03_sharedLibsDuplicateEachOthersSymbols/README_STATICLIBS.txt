
These examples illustrate the limitations of the
loader (dynamic linker) when handling the cases 
of duplicate symbols.

The following scenario is covered:
- two shared libraries of distinctly different ABIs
  are internally linked against the same static library
  and therefore feature the same set of symbols. 
  According to the standard linker's rules, the
  static library symbols declared non-static become
  visible symbols in the shared library. 
  
- when resolving the symbols, the loader employs
  the minimum of intelligence - as soon as it finds
  the very first symbol that matches the requirements
  it uses it, and ignores all the subsequent findings.
  
- the loader fortunately observes the namespace as
  part of the symbol. If we want to ensure that static
  library symbols never get obfuscated/lost/ignored,
  we must enclose the static library symbols into the
  unique namespace.
  
  Misconception dispelled: when namespaced shared lib
  links in (un-namespaced) static lib, the methods of
  the static lib do NOT get encapsulated into the shared
  lib namespaces. More general statement is: linking
  does not pack symbols into the client binary namespaces.

