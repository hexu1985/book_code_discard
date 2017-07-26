#include "libraryio.h"
#include "library.h"

bool saved(false);

int main() {
   Library lib;
   LibraryIO libio(&lib);
   while(1) {
      switch(libio.nextTask()) {
      case LibraryIO::READ: libio.read();
         saved = false;
         break;
      case LibraryIO::ADD: libio.enterData();
         saved = false;
         break;
      case LibraryIO::FIND: libio.find();
         break;
      case LibraryIO::REMOVE: libio.remove();
         saved = false;
         break;
      case LibraryIO::SAVE: libio.save();
         saved = true;
         break;
      case LibraryIO::LIST: libio.list();
         break;
      case LibraryIO::QUIT: libio.prepareToQuit(saved);
         break;
      default:
         break;
      }
   }
}

