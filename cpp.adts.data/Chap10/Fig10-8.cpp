/*------------------------------------------------------------------------- 
   Use the standard sort algorithm to sort a vector of stack<int>s.
-------------------------------------------------------------------------*/
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// Less-than function for stack
template <typename ElementType>
bool operator<(const stack<ElementType> & s1,
               const stack<ElementType> & s2)
{ 
   return s1.top() < s2.top(); 
}

// Output a stack
template <typename ElementType>
void dump(stack<ElementType> s);

int main()
{
   vector< stack<int> > s(4);
   s[0].push(90); s[0].push(80);
   s[1].push(10);
   s[2].push(11); s[2].push(22);
   s[3].push(12); s[3].push(56); s[3].push(34);
   cout << "Stacks in original order:\n";
   for (int i = 0; i < 4; i++)
   {
      cout << "Stack #" << i << ": ";
      dump(s[i]);
      cout << endl;
   }
 
   sort(s.begin(), s.end());
   cout << "\nStacks in sorted order:\n"; 
   for (int i = 0; i < 4; i++)
   {
     cout << "Stack #" << i << ": ";
     dump(s[i]);
     cout << endl;
   }

}

/*--------------------------------------------------------------------------
  Display stack elements from top to bottom.
  Precondition:  ElementType is a type parameter.
  Postcondition: Elements of s are output to cout from top to bottom.
 -------------------------------------------------------------------------*/
template <typename ElementType>
void dump(stack<ElementType> s)
{
  cout << " Top-->";
  while (!s.empty())
  {
    cout << s.top() << "  ";
    s.pop();
  }
}
