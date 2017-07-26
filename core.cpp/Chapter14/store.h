// Listing 14.14	Class specification for the Store class (file store.h).

// file store.h 

#ifndef STORE_H
#define STORE_H
#include "inventory.h"
#include "file.h"

class Store {
public:
  void loadData(Inventory &inv);
  int findCustomer(Inventory& inv);
  void processItem(Inventory& inv);
  void saveData(Inventory &inv);
} ;
#endif


