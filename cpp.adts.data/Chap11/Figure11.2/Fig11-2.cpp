/*-- Class AddressCounter --------------------------------------------------
             Models occurrences of IP addresses in a login file.
 -------------------------------------------------------------------------*/

#include <string>
#include <iostream>
using namespace std;

class AddressCounter
{
 public:
  /*** Function Members ***/
  AddressCounter();
  /*------------------------------------------------------------------------
    Precondition:  None.
    Postcondition: myAddress is an empty string and myCount is 0.
   -----------------------------------------------------------------------*/
  
  void read(istream & in);
  /*------------------------------------------------------------------------
    Precondition:  istream in is open.
    Postcondition: Value for AddressCounter object has been read from in.
   -----------------------------------------------------------------------*/
 
  void print(ostream & out) const;
  /*------------------------------------------------------------------------
    Precondition:  ostream out is open.
    Postcondition: Value of AddressCounter object has been output to out.
   -----------------------------------------------------------------------*/

  void tally();
  /*------------------------------------------------------------------------
    Precondition:  None.
    Postcondition: myCount has been incremented by 1.
   -----------------------------------------------------------------------*/

  bool operator==(const AddressCounter & addr);
  /*------------------------------------------------------------------------
    Precondition:  None.
    Postcondition: True is returned if this address and addr have the
        same address, and false otherwise.
   -----------------------------------------------------------------------*/

 private:
  /*** Data Members ***/
  string myAddress;
  int myCount;
}; // end of class declaration

//--- Definition of constructor
inline AddressCounter::AddressCounter()
: myAddress(""), myCount(0)
{ }

//--- Definition of read()
inline void AddressCounter::read(istream & in)
{
  in >> myAddress;
  myCount = 1;
}

//--- Definition of print()
inline void AddressCounter::print(ostream & out) const
{
  out << myAddress << "\t occurs " << myCount << " times\n";
}

//--- Definition of tally()
inline void AddressCounter::tally()
{
  myCount++;
}

//--- Definition of == operator
inline bool AddressCounter::operator==(const AddressCounter & addr)
{
  return myAddress == addr.myAddress;
}

/*--------------------------------------------------------------------------
  Program to read IP addresses from a file and produce a list of distinct
  addresses and a count of how many times each appeared in the file. 
 -------------------------------------------------------------------------*/

#include <fstream>
#include <cassert>
#include <list>
#include <algorithm>

int main()
{
   string fileName;                    // name of file of IP addresses
   ifstream inStream;                  // open stream to file of addresses
   cout << "Enter name of file containing IP addresses: ";
   cin >> fileName;
   inStream.open(fileName.data());
   assert(inStream.is_open());
 
   list<AddressCounter> addressList;   // list of AddressCounter objects
   AddressCounter addr;
   for (;;)                            // loop:
   {
      addr.read(inStream);             //   read an address

      if (inStream.eof()) break;       //   if eof, quit

      list<AddressCounter>::iterator   //   check if addr already in list
         it = find(addressList.begin(), addressList.end(), addr);
      if (it != addressList.end())     //   found
         (*it).tally();                //   increment its count
      else
         addressList.push_back(addr);  //   else add it to the list
   }                                   //   end loop
                                       //   output the list
   cout << "\nList of addresses:\n\n";
   for (list<AddressCounter>::iterator it = addressList.begin();
                                       it != addressList.end(); it++)
      (*it).print(cout);
}
