/*-------------------------------------------------------------------------- 
 Demonstration of what can happen when array indices get out of bounds.

  Input:  Three arrays of integers
  Output: The three arrays before and after modification using
          out-of-range indices.
 -------------------------------------------------------------------------*/

#include <iostream>
using namespace std;

const int CAPACITY = 4;
typedef int IntArray[CAPACITY];

void read(IntArray theArray, int capacity, int numValues);
void display(IntArray theArray, int numValues);

int main()
{
   IntArray a, b, c;
   
   cout << "Enter " << CAPACITY << " integer values for:\n";
   cout << "Array a: ";
   read(a, CAPACITY, CAPACITY);
   cout << "Array b: ";
   read(b, CAPACITY, CAPACITY);
   cout << "Array c: ";
   read(c, CAPACITY, CAPACITY);

   cout << "\n------ Part I of the demonstration -----\n\n"
           "The arrays are:\n";
   cout << "a: ";
   display(a, CAPACITY);
   cout << "b: ";
   display(b, CAPACITY);
   cout << "c: ";
   display(c, CAPACITY);

   //--- Now change array elements in b, but using
   //--- some out-of-range indices.
   int below = -3,
       above = 6;
   b[below] = -999;
   b[above] = 999;

   cout << "\n------ Part II of the demonstration -----\n\n"
           "The arrays after out-of-range errors are:\n";
   cout << "a: ";
   display(a, CAPACITY);
   cout << "b: ";
   display(b, CAPACITY);
   cout << "c: ";
   display(c, CAPACITY);
   cout << endl;
 }

//--- Insert here the definition of read() from Figure 3.4 
//--- and the definition of display() from Figure 3.3 

#include <cassert>

void read(IntArray theArray, int capacity, int numValues)
/*-------------------------------------------------------------------------
  Input values into an array of integers from the keyboard.

  Preconditions: 0 <= numValues <= capacity, which is the capacity of
       theArray.
  Postcondition: numValues integers entered from the keyboard have been
       stored in the first numValues positions of theArray.
 -------------------------------------------------------------------------*/
{
   assert (numValues >= 0 && numValues <= capacity);

   for (int i = 0; i < numValues; i++)
      cin >> theArray[i];
}

void display(int theArray[], int numValues)
/*-------------------------------------------------------------------------
  Display values in an array of integers.
 
  Precondition:  0 <= numValues < capacity of theArray.
  Postcondition: The first numValues integers stored in theArray have
      been output to cout.
 -------------------------------------------------------------------------*/
{
  for (int i = 0; i < numValues; i++)
    cout << theArray[i] << "  ";
  cout << endl;
}
