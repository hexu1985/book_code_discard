// Listing 14.9	Implementation of class Customer (file customer.cpp).

// file customer.cpp 

#include <iostream> 
using namespace std;
#include "customer.h"                  // this is a necessity

Customer::Customer () 
{ count = 0; } 

void Customer::set(const char *nm, const char *ph)
{ strcpy(name,nm); strcpy(phone,ph); }       // in appendCust()

void Customer::addMovie(int id) 
{ movies[count++] = id; }        // in appendCust(), checkOut()
	
int Customer::removeMovie(int id)         // used in checkIn()
{ int idx;
  for (idx=0;  idx < count;  idx++)  // find the movie
    if (movies[idx] == id) break;
  if (idx == count) return 0;        // give up if not found
  while (idx < count - 1)
  { movies[idx] = movies[idx+1];     // shift tail to the left
    idx++; }
  count--;                           // decrement movie count
  return 1; }                        // report success
    
void Customer::getCustomer(char *nm, char *ph, // saveData()
  int &cnt, int m[]) const        // Inventory::getCustomer()
{ strcpy(nm,name); strcpy(ph,phone); cnt = count;
  for (int i=0;  i < count;  i++)	 
    m[i] = movies[i]; }


