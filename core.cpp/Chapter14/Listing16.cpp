// Listing 14.16	Implementation of function main() Store (file video.cpp).

// file video.cpp 

#include <iostream> 
using namespace std;
#include "store.h"                  // this is a necessity

int main()
{ 
   Inventory inv;  Store store;        // define objects
   store.loadData(inv);                // load data 
   while(true)
   { int result = store.findCustomer(inv); // check results
     if (result == 0) break;           // terminate program
	 if (result == 2)                  // 1 if not found
		 store.processItem(inv); }     // process the cassette
    store.saveData(inv);               // save database
    return 0; 
   }
