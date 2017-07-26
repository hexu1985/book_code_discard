// Listing 14.8	Implementation of class Item (file item.cpp).

// file item.cpp 

#include <iostream> 
using namespace std;
#include "item.h"                  // this is a necessity

	void Item::set (const char *s, int num, int qty, int type)
	{ strcpy(title,s);  id=num;  quant=qty;  category=type; }

	int Item::getQuant() const  // used by Inventory::checkOut()
	{ return quant; }
	
	int Item::getId() const 
	{ return id; }    // in printRental(), checkOut(), checkIn()
	
	void Item::getItem(char* name, int &num, int& qty, 
		           int &type) const   // used by File::saveItem()
	{ strcpy(name,title);  num = id;  
	  qty = quant;  type = category; }
	
	void Item::printItem() const    // used by printRental()
	{ cout.setf(ios::left,ios::adjustfield); 
	  cout.width(5);  cout << id;   // it knows its print formats
	  cout.width(27);  cout << title;
      switch (category) {           // different item subtypes
        case 1:  cout << "   feature";  break;
        case 2:  cout << "   comedy";  break;
        case 3:  cout << "   horror";  break; }
      cout << endl; }

	void Item::incrQty(int qty) // used in checkOut(), checkIn()
       { quant += qty; }

