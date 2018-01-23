/**------------------------------------------------------------------------
   Demonstration of the heap algorithms in STL.
 ------------------------------------------------------------------------*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;

template <typename DataType>
void displayTree(DataType x[], int n);

template <typename DataType>
void displayOneLevel(DataType x[], int numRows,
                     int row, int row_begin, int row_end);

int main()
{
   int x[11] = {87, 35, 74, 67, 79, 84, 76, 73, 81, 32};
   make_heap(x, x + 10);
   displayTree(x, 10);

   x[10] = 83;
   push_heap(x, x + 11);
   cout << "\nAfter push_heap(83):\n\n";
   displayTree(x, 11);

   pop_heap(x, x+11);
   cout << "\nAfter pop_heap( ):\n\n";
   displayTree(x, 10);

   sort_heap(x, x+10);
   cout << "\nAfter sort_heap( ), array contains:\n\n";
   for (int i = 0; i < 10; i++)
      cout << x[i] << "  ";
   cout << endl;
}

template <typename DataType>
void displayTree(DataType x[], int n)
/*------------------------------------------------------------------------
   Display a binary tree stored in an array in tree format.

   Precondition:  Binary tree is stored in an array x; n is the
       number of nodes in the tree .
   Postcondition: The binary tree has been displayed.
 ------------------------------------------------------------------------*/
{
   int beginIndex = 0,  // index of first node on some level
       endIndex = 0,    //    "   " last node on this level
       rowLength,       // length of current row
       numLevels = int(ceil(log(double(n)) / log(2.0)));  // Number of levels

   for (int level = 0; level < numLevels; level++)
   {
      displayOneLevel(x, numLevels, level, beginIndex, endIndex);
      rowLength = endIndex - beginIndex + 1;
      beginIndex = endIndex + 1;
      endIndex = min(endIndex + 2*rowLength, n - 1);
   }
}

template <typename DataType>
void displayOneLevel(DataType x[], int numRows,
                 int level, int beginIndex, int endIndex)
/*------------------------------------------------------------------------
   Display nodes on one level of a binary tree stored in an array.

   Precondition:  Binary tree is stored in an array x; numRows is the
       number of rows used to display the entire tree, level is the 
       current level being displayed; and beginIndex and endIndex are 
       the indices in x of the first and last nodes on this level .
   Postcondition: Nodes on this level of binary tree have been 
       displayed.
 ------------------------------------------------------------------------*/
{
   int skip = int(pow(2.0, numRows - level) - 1);  
                                     // space between items in row
   for (int i = beginIndex; i <= endIndex; i++)
   {
      cout << setw(skip) << " ";
      cout << setw(2) << x[i];
      cout << setw(skip) << " ";
   }
   cout << "\n\n";
}
