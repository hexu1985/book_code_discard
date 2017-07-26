// Listing 14.7	Class specification for the Customer class (file customer.h).

// file customer.h 

#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer 
{ 
  char name[20], phone[15];
  int count;
  int movies[10];
public:
  Customer ();
  void set(const char *nm, const char *ph);
  void addMovie(int id);
  int removeMovie(int id);
  void getCustomer(char *nm, char *ph, int &cnt, int m[]) const;
 } ;

#endif


