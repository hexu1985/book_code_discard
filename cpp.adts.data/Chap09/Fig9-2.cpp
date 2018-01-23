/*-------------------------------------------------------------------------
   Program to illustrate the use of a function template to display
   an array with elements of any type for which << is defined. 

   Output:  An array of ints and an array of doubles using display()
 -------------------------------------------------------------------------*/

#include <iostream>
using namespace std;

template <typename ElementType>
void display(ElementType array[], int numElements)
/*-------------------------------------------------------------------------
  Display elements of any type (for which the output operator is defined)
  stored in an array.

  Precondition:  ElementType is a type parameter.
  Postcondition: First numElements of array have been output to cout.
 ------------------------------------------------------------------------*/
{
   for (int i = 0; i < numElements; i++)
      cout << array[i] << "  ";
   cout << endl;
}

int main()
{
   double x[] = {1.1, 2.2, 3.3, 4.4, 5.5};
   display(x, 5);
   int num[] = {1, 2, 3, 4};
   display (num, 4);
}
