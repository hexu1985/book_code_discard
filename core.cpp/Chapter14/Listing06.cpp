// Listing 14.6	Class specification for the Item class (file item.h).

// file item.h 

#ifndef ITEM_H
#define ITEM_H

class Item 
{
 protected:
	char title[26];
	int id, quant, category;  
 public:
	void set (const char *s, int num, int qty, int type);
	int getQuant() const;
	int getId() const;
	void getItem(char* name, int &num, int& qty, int &type) const;
	void printItem() const;
	void incrQty(int qty);
 } ;

#endif


