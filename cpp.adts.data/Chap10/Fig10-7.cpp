/*-------------------------------------------------------------------------- 
   Program to illustrate use of C++'s standard sort algorithm.

   Output:  A sorted vector of ints and a sorted deque of doubles.
--------------------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

template <typename Container>
void display(const Container & c);

int main()
{
  int ints[] = {555, 33, 444, 22, 222, 777, 1, 66};
  vector<int> v(ints, ints + 5);      // Use only first 5 elements of ints
  sort(v.begin(), v.end());
  cout << "Sorted vector of integers:\n";
  display(v);

  double dubs[] = {55.5, 3.3, 44.4, 2.2, 22.2, 77.7, 0.1};
  deque<double> d(dubs, dubs + 7);    // Use all 7 elements of dubs
  sort(d.begin(), d.end());
  cout << "\nSorted deque of doubles:\n";
  display(d);
}

template <typename Container>
void display(const Container & c)
/*-------------------------------------------------------------------------
  Function template to display elements of any type (for which the output
  operator is defined) stored in a container c (for which [] and size() 
  are defined).

  Precondition:  Container is a type parameter.  
  Postcondition: Values stored in c are output to out. 
 -------------------------------------------------------------------------*/
{
  for (int i = 0; i < c.size(); i++)
    cout << c[i] << "  ";
  cout << endl;
}
