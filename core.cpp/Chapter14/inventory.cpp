// Listing 14.11	Implementation of class Inventory (file inventory.cpp).

// file inventory.cpp 

#include <iostream> 
using namespace std;
#include "inventory.h"                  // this is a necessity

Inventory::Inventory()
 { itemCount = itemIdx = 0;  custCount = custIdx = 0; }

void Inventory::appendItem (const char* ttl, int id, 
                            int qty, int cat)
{ if (itemCount == MAXM)                   // used in loadData()
    { cout << "\nNo space to insert item"; }
  else
	{ itemList[itemCount++].set(ttl,id,qty,cat); } }

void Inventory::appendCust (const char* nm, const char* ph,
							int cnt, const int *movie)  
{ if (custCount == MAXC)                   // used in loadData()
    { cout << "\nNo space to insert customer";  return; }
  custList[custCount++].set(nm,ph); 
  for (int j=0; j < cnt;  j++) 
    custList[custCount-1].addMovie(movie[j]); }

int Inventory::getItem(Item &item)         // used in saveData()
{ if (itemIdx == itemCount) 
   {  itemIdx = 0; return 0; }
  item = itemList[itemIdx++];
  return 1; }

int Inventory::getCustomer(char* nm, char* ph, int &cnt, int *m)
{ if (custIdx == custCount)     // in findCustomer(), saveData()
   {  custIdx = 0; return 0; }
  custList[custIdx++].getCustomer(nm,ph,cnt,m);
  return 1; }

void Inventory::printRental(int id)  // used in findCustomer()
{ for (itemIdx = 0;  itemIdx < itemCount;  itemIdx++)
   { if (itemList[itemIdx].getId() == id)
       { itemList[itemIdx].printItem(); break; } }
  itemIdx = 0;}

int Inventory::checkOut(int id)      // used in processItem()
{ for (itemIdx = 0; itemIdx < itemCount; itemIdx++)
    if (itemList[itemIdx].getId() == id) break;
  if (itemIdx == itemCount) 
  { itemIdx = custIdx = 0; return 0; }
  if (itemList[itemIdx].getQuant() == 0) 
  { itemIdx = custIdx = 0; return 1; }
  itemList[itemIdx].incrQty(-1);
  custList[custIdx - 1].addMovie(id);
  itemIdx = custIdx = 0;
  return 2; } 

void Inventory::checkIn(int id)      // used in processItem()
{ if (custList[custIdx - 1].removeMovie(id)==0) 
   { cout << " Movie is not found\n";  
     itemIdx = custIdx = 0;  return; }
  for (itemIdx = 0;  itemIdx < itemCount;  itemIdx++)
   { if (itemList[itemIdx].getId() == id)
     { itemList[itemIdx].incrQty(1);  break; } }
  itemIdx = custIdx = 0;
  cout << " Movie is returned\n"; }

