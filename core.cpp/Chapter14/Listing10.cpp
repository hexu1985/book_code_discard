// Listing 14.10	Class specification for the Inventory class (file inventory.h).

// file inventory.h 

#ifndef INVENTORY_H
#define INVENTORY_H
#include "item.h"
#include "customer.h"

class Inventory {
protected:
    enum { MAXM = 5, MAXC = 4 } ;    // just for the prototype
    Item itemList[MAXM];
    Customer custList[MAXC];
    int itemCount, custCount;
    int itemIdx, custIdx;
public:
  Inventory ();
  void appendItem (const char* ttl, int id, int qty, int cat);
  void appendCust (const char* nm, const char* ph, 
                   int cnt, const int *m);
  int getItem(Item& item);
  int getCustomer(char* nm, char* ph, int &cnt, int *m);
  void printRental(int id);
  int checkOut(int id);
  void checkIn(int id);
 } ;

#endif


