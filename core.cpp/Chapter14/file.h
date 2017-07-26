// Listing 14.12	Class specification for the File class (file file.h).

// file file.h 

#ifndef FILE_H
#define FILE_H
#include "item.h"
#include <fstream>
using namespace std;

class File
{ fstream f;
  static void trim(char buffer[]);
  enum { TWIDTH = 27, IWIDTH = 5, QWIDTH = 6, 
	     NWIDTH = 18, PWIDTH = 16 } ;
public:
  File(const char name[], int mode);
  int getItem(char *ttl, int &id, int &qty, char &type);
  void saveItem(const Item &item);
  int getCustomer(char *name, char *phone, int &count, int *m);
  void saveCustomer(const char *nm, const char *ph, 
                    int cnt, int *m);
} ;

#endif

