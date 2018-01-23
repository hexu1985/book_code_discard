/*-------------------------------------------------------------------------
                  Driver program to test the Stack class.
 -------------------------------------------------------------------------*/

#include <iostream>
#include <iomanip>
using namespace std;

#include "DStackT.h"

template <typename T>
void print(Stack<T> st)
{ st.display(cout); }

int main()
{
   int cap;
   cout << "Enter stack capacity: ";
   cin >> cap;

   Stack<int> intSt;    // stack of ints
   Stack<char> charSt;  // stack of chars
   for (int i = 1; i <= 4; i++)
      intSt.push(100*i);
   cout << intSt << endl;
   for (char ch = 'A'; ch <= 'D'; ch++)
      charSt.push(ch); 
   cout << charSt << endl;
  
   cout << "Contents of stack intSt (via print):\n";
   print(intSt); cout << endl;

   Stack<int> t;
   t = intSt;
   cout << "Contents of stack t after t = stInt (via print):\n";
   print(t); cout << endl;

   cout << "Stack t empty? " << boolalpha << t.empty() << endl;

   cout << "Top value in t: " << t.top() << endl;

   while (!t.empty())
   {
     cout << "Popping t:  " << t.top() << endl;
     t.pop();
   }
   cout << "Stack t empty? " << t.empty() << endl;
   cout << "Top value in t: " << t.top() << endl;
   cout << "Trying to pop t: " << endl;
   t.pop();
}
