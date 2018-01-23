/*-- BigInt.cpp-------------------------------------------------------------
                This file implements BigInt member functions.
--------------------------------------------------------------------------*/

#include <iostream>
using namespace std;

#include "BigInt.h"

//--- Definition of read()
void BigInt::read(istream & in)
{
  static bool instruct = true;
  if (instruct)
  {
     cout << "Enter " << DIGITS_PER_BLOCK << "-digit blocks, separated by "
            "spaces.\nEnter a negative integer in last block to signal "
            "the end of input.\n\n";
    instruct = false;
  }
  short int block;
  const short int MAX_BLOCK = (short) pow(10.0, DIGITS_PER_BLOCK) - 1;
  for (;;)
  {
    in >> block;
    if (block < 0) return;

    if (block > MAX_BLOCK)
      cerr << "Illegal block -- " << block << " -- ignoring\n";
    else
      myList.push_back(block);
  }
}

//--- Definition of display()
void BigInt::display(ostream & out) const
{ 
   int blockCount = 0;
   const int BLOCKS_PER_LINE = 20;   // number of blocks to display per line

   for (list<short int>::const_iterator it = myList.begin(); ; )
   {
      out << setfill('0'); 
      if (blockCount == 0)
         out << setfill(' '); 
 
      if (it == myList.end())
         return;

      out << setw(3) << *it;
      blockCount++ ;

      it++;
      if (it != myList.end())
      {
         out << ',';
         if (blockCount > 0 && blockCount % BLOCKS_PER_LINE == 0)
            out << endl;
      }
   }
}

//--- Definition of operator+()
BigInt BigInt::operator+(BigInt addend2)
{
   BigInt sum;
   short int first,                  // a block of 1st addend (this object)
             second,                 // a block of 2nd addend (addend2)
             result,                 // a block in their sum
             carry = 0;              // the carry in adding two blocks

   list<short int>::reverse_iterator // to iterate right to left
      it1 = myList.rbegin(),         //   through 1st list, and
      it2 = addend2.myList.rbegin(); //   through 2nd list

   while (it1 != myList.rend() || it2 != addend2.myList.rend())
   {
      if (it1 != myList.rend())
      { 
         first = *it1;
         it1++ ;
      }
      else
         first = 0;
      if (it2 != addend2.myList.rend())
      {
         second = *it2;
         it2++ ;
      }
      else
         second = 0;

      short int temp = first + second + carry;
      result = temp % 1000;
      carry = temp / 1000;
      sum.myList.push_front(result);
   }

   if (carry > 0)
      sum.myList.push_front(carry);

   return sum;
}
