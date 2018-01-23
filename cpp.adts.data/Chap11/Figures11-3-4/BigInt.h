/*-- BigInt.h -------------------------------------------------------------
 
  This header file defines the data type BigInt for processing 
  integers of any size.
  Basic operations are:
     Constructor
     +:         Addition operator
     read():    Read a BigInt object
     display(): Display a BigInt object
     <<, >> :   Input and output operators
-------------------------------------------------------------------------*/

#include <iostream>
#include <iomanip>       // setfill(), setw()
#include <list>

#ifndef BIGINT
#define BIGINT

const int DIGITS_PER_BLOCK = 3;
class BigInt
{
 public:
  /******** Function Members ********/
  /***** Constructor *****/
  // Let the list<short int> constructor take care of this.

  /***** read *****/
  void read(istream & in);
  /*-----------------------------------------------------------------------
    Read a BigInt.

    Precondition:  istream in is open and contains blocks of nonnegative
        integers having at most DIGITS_PER_BLOCK digits per block.
    Postcondition: Blocks have been removed from in and added to myList.
   -----------------------------------------------------------------------*/

  /***** display *****/
  void display(ostream & out) const;
  /*-----------------------------------------------------------------------
    Display a BigInt.

    Precondition:  ostream out is open.
    Postcondition: The large integer represented by this BigInt object
        has been formatted with the usual comma separators and inserted
        into ostream out. 
  ------------------------------------------------------------------------*/

  /***** addition operator *****/
  BigInt operator+(BigInt addend2);
  /*------------------------------------------------------------------------
    Add two BigInts.

    Precondition:  addend2 is the second addend.
    Postcondition: The BigInt representing the sum of the large integer
       represented by this BigInt object and addend2 is returned.
  ------------------------------------------------------------------------*/

 private:
  /*** Data Members ***/
  list<short int> myList;
};  // end of BigInt class declaration

//------ Input and output operators
inline istream & operator>>(istream & in, BigInt & number)
{
  number.read(in);
  return in;
}

inline ostream & operator<<(ostream & out, const BigInt & number)
{
  number.display(out);
  return out;
}

#endif
