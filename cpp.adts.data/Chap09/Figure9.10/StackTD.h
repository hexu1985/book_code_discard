//***** For documentation, see Fig. 8.3. *****//

#ifndef STACK_DEQUE
#define STACK_DEQUE

#include <iostream>
#include <deque>

template<typename StackElement>
class Stack
{
 public:
  /***** Function Members *****/
  Stack();
  bool empty() const;
  void push(const StackElement & value);
  void display(ostream & out) const;
  StackElement top() const;
  void pop();

 private:
  /***** Data Members *****/
  deque<StackElement> myDeque;   // deque to store elements

}; // end of class declaration

//--- Definition of constructor
template <typename StackElement>
inline Stack<StackElement>::Stack()
{  /* Let deque's constructor do the work */ }

//--- Definition of empty operation
template <typename StackElement>
inline bool Stack<StackElement>::empty() const
{
   return myDeque.empty();
}

//--- Definition of push operation
template <typename StackElement>
void Stack<StackElement>::push(const StackElement & value)
{
   myDeque.push_back(value);
}


//--- Definition of display operation
template <typename StackElement>
void Stack<StackElement>::display(ostream & out) const
{
   for (int pos = myDeque.size() - 1; pos >= 0; pos--)
      out << myDeque[pos] << endl;
}

//--- Definition of top operation
template <typename StackElement>
StackElement Stack<StackElement>:: top() const
{
   if (!myDeque.empty())
      return myDeque.back();
   //else
   cerr << "*** Stack is empty ***\n";
}


//--- Definition of pop operation
template <typename StackElement>
void Stack<StackElement>:: pop()
{
  if (!myDeque.empty())
    myDeque.pop_back();
  else
    cerr << "*** Stack is empty -- can't remove a value ***\n";
}

#endif
