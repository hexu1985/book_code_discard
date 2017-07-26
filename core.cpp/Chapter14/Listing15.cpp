// Listing 14.15	Implementation of class Store (file store.cpp).

// file store.cpp 

#include <iostream> 
using namespace std;
#include "store.h"                  // this is a necessity

void Store::loadData(Inventory &inv)
{  File itemsIn("Item.dat",ios::in);          // item database
   char ttl[27], category; int id, qty, type;  // item data 
   cout << "Loading database ... " << endl;
   while (itemsIn.getItem(ttl,id,qty,category)==1) // read in
   {  switch (category) {     // set category for the subtype
        case 'f':  type = 1;  break;
        case 'c':  type = 2;  break;
        case 'h':  type = 3;  break; } 
      inv.appendItem(ttl,id,qty,type); }
  File custIn("Cust.dat",ios::in);        // customer database
  char name[25], phone[15]; int movies[10], count;
  while (custIn.getCustomer(name,phone,count,movies)==1) 
  { inv.appendCust(name,phone,count,movies); } } // pump data

int Store::findCustomer(Inventory& inv)
{ char buffer[200]; char name[25], phone[13]; 
  int count, movies[10];
  cout << "Enter customer phone (or press Return to quit) ";
  cin.getline(buffer,15);
  if (strcmp(buffer,"")==0) return 0; // quit if no data entered
  bool found = false;
  while (inv.getCustomer(name,phone,count,movies) != 0)
   { if (strcmp(buffer,phone) == 0)   // search for the phone
       { found = true;  break; } }    // stop if phone found
  if (!found)
  { cout << "\nCustomer is not found" << endl; 
    return 1; }                       // give up if not found
  cout.setf(ios::left,ios::adjustfield);  
  cout.width(22);  cout << name << phone << endl; // print data
  for (int j = 0; j < count;  j++) 
    { inv.printRental(movies[j]);}     // print movie Id's
  cout << endl;
  return 2; }                          // success code

void Store::processItem(Inventory& inv)
 { int cmd, result, id;
   cout << " Enter movie id: ";
   cin >> id;                          // search attribute
   cout << " Enter 1 to check out, 2 to check in: ";
   cin >> cmd;
   if (cmd == 1)
   { result = inv.checkOut(id);        // analyze return value
     if (result == 0)                  // not found
		cout << "Movie is not found " << endl;
	 else if (result == 1)             // out of stock
		cout << "Movie is out of stock" << endl;
	 else                              // it is a success
        cout << " Renting is confirmed\n"; } 
    else if (cmd == 2) 
 	   inv.checkIn(id);              // feedback in checkIn()
    cin.get(); }                       // eliminate CR from line

void Store::saveData(Inventory &inv)
{ File itemsOut("Item.out",ios::out);  Item item; // item file
  while (inv.getItem(item))            // no internal structure
    itemsOut.saveItem(item);           // save each item
  File custOut("Cust.out",ios::out);   // customer output file
  char name[25], phone[13];  int count, movies[10];
  cout << "Saving database ... " << endl;
  while(inv.getCustomer(name,phone,count,movies))  // pump data
	  custOut.saveCustomer(name,phone,count,movies); }

