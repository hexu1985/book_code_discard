// Listing 14.13	Implementation of class File (file file.cpp).

// file file.cpp 

#include <iostream> 
using namespace std;
#include "file.h"                  // this is a necessity

File::File(const char name[], int mode) 
{ f.open(name,mode);          // used in loadData(), saveData()
  if (f.fail())               // if (f.is_open()) is OK, too
   { cout <<" File is not open\n";  exit(1); } }
  
int File::getItem(char *ttl, int &id, int &qty, char &type)
{ char buffer[200];                   // in loadData()
  f.get(buffer,TWIDTH);
  trim(buffer);
  strcpy(ttl,buffer);       // it knows file structure
  f >> id;  f >> qty;  f >> type;  f.getline(buffer,4);
  if (!f) return 0;
  return 1; }

void File::saveItem(const Item &item) // in saveData()
{ char tt[27]; int id, qty, type;
  item.getItem(tt,id,qty,type);
  f.setf(ios::left,ios::adjustfield); 
  f.width(TWIDTH);  f << tt;          // it knows file format
  f.setf(ios::right,ios::adjustfield); 
  f.width(IWIDTH);  f << id ; 
  f.width(QWIDTH);  f << qty; 
  switch (type) {        // different for different subtypes
    case 1:  f << "   f\n";  break;
    case 2:  f << "   c\n";  break;
    case 3:  f << "   h\n";  break; } }

int File::getCustomer(char *name,char *phone,int &count,int *m)
{ char buffer[200];                  // in loadData()
  f.get(buffer,NWIDTH);
  trim(buffer);
  strcpy(name,buffer);
  f >> buffer;  f >> count;          // it knows file structure
  strcpy(phone,buffer);
  for (int i=0;  i < count;  i++)
    f >> m[i];
  f.getline(buffer,2);
  if (!f) return 0;
  return 1; }

void File::saveCustomer(const char *nm, const char *ph, 
                   int cnt, int *m)            // in saveData()
{ f.setf(ios::left,ios::adjustfield); f.width(NWIDTH);
  f << nm;
  f.setf(ios::right,ios::adjustfield); f.width(PWIDTH);
  f << ph << endl << cnt;            // it knows file structure
  for (int i=0;  i < cnt;  i++)
  { f.width(6); f << m[i]; }
  f << endl; }

void File::trim(char buffer[])   // in getItem(), getCustomer()
{ for (int j = strlen(buffer)-1; j>0; j--)
    if (buffer[j]==' '||buffer[j]=='\n') 
      buffer[j] = '\0';
    else 
      break; }

