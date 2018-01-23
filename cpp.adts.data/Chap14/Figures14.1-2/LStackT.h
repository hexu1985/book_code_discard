/*-- LStack.h --------------------------------------------------------------
 
  This header file contains a template for a Stack data type.
  Basic operations:
    constructor:  Constructs an empty stack
    empty:        Checks if a stack is empty
    push:         Modifies a stack by adding a value at the top
    top:          Accesses the top stack value; leaves stack unchanged
    pop:          Modifies stack by removing the value at the top
    display:      Displays all the stack elements
  Note: Execution terminates if memory isn't available for a stack element.
--------------------------------------------------------------------------*/

#include <iostream>
using namespace std;

#ifndef LSTACKT
#define LSTACKT

template<typename StackElement>
class Stack
{
 public:
 /***** Function Members *****/
 /***** Constructors *****/

  Stack();
  /*----------------------------------------------------------
    Construct a Stack object.

    Precondition:  None.
    Postcondition: An empty Stack object has been constructed
        (myTop is initialized to a null pointer).
  -----------------------------------------------------------*/

  Stack(const Stack & original);
  /*------------------------------------------------------------------------
    Copy Constructor 

    Precondition:  original is the stack to be copied and 
        is received as a const reference parameter.
    Postcondition: A copy of original has been constructed.
  ------------------------------------------------------------------------*/

 /***** Destructor *****/
  ~Stack(); 
  /*------------------------------------------------------------------------
    Class destructor 

    Precondition:  None
    Postcondition: The linked list in the stack has been 
      deallocated.
  ------------------------------------------------------------------------*/

 /***** Assignment *****/
  Stack & operator= (const Stack & original);
  /*------------------------------------------------------------------------
    Assignment Operator 

   Precondition:  original is the stack to be assigned and is received as
        a const reference parameter.
   Postcondition: The current stack becomes a copy of original and a 
       reference to it is returned.
  ------------------------------------------------------------------------*/

  bool empty() const;
  /*------------------------------------------------------------------------
    Check if stack is empty.

    Precondition:  None.
    Postcondition: Returns true if stack is empty and false otherwise.
  ------------------------------------------------------------------------*/

  void push(const StackElement & value);
  /*------------------------------------------------------------------------
    Add a value to a stack. 

    Precondition:  value is to be added to this stack.
    Postcondition: value is added at top of stack.     
    ----------------------------------------------------------------------*/

  void display(ostream & out) const;
  /*------------------------------------------------------------------------
    Display values stored in the stack.

    Precondition:  ostream out is open.
    Postcondition: Stack's contents, from top down, have been output to out.
  ------------------------------------------------------------------------*/

  StackElement top() const;
  /*------------------------------------------------------------------------
    Retrieve value at top of stack (if any).

    Precondition:  Stack is nonempty.
    Postcondition: Value at top of stack is returned, unless the stack is
        empty; in that case, an error message is displayed and a "garbage
        value" is returned.
  ------------------------------------------------------------------------*/

  void pop();
  /*------------------------------------------------------------------------
    Remove value at top of stack (if any).

    Precondition:  Stack is nonempty.
    Postcondition: Value at top of stack has been removed, unless stack is
        empty; in that case, an error message is displayed and execution
        allowed to proceed.
  ------------------------------------------------------------------------*/ 

 private:
   /*** Node class ***/
   class Node
   {
    public:
      StackElement data;
      Node * next;
      //--- Node constructor
      Node(StackElement value, Node * link = 0)
      /*--------------------------------------------------------------------
        Precondition:  value is received
        Postcondition: A Node has been constructed with value in its data
            part and itb next part set to link (default 0).
       -------------------------------------------------------------------*/
      { data = value; next = link; }

  };

  typedef Node * NodePointer;

  /***** Data Members *****/
  NodePointer myTop;      // pointer to top of stack

}; // end of class declaration

//--- Definition of Stack constructor
template<typename StackElement>
inline Stack<StackElement>::Stack()
  : myTop(0)
{}

//--- Definition of Stack copy constructor
template<typename StackElement>
Stack<StackElement>::Stack(const Stack<StackElement> & original)
{
  myTop = 0;
  if (!original.empty())
    {
      // Copy first node
      myTop = new Stack<StackElement>::Node(original.top());

      // Set pointers to run through the stack's linked lists
      Stack<StackElement>::NodePointer lastPtr = myTop,
	origPtr = original.myTop->next;

      while (origPtr != 0)
	{
	  lastPtr->next = new Stack<StackElement>::Node(origPtr->data);
	  lastPtr = lastPtr->next;
	  origPtr = origPtr->next;
	}
    }
}

//--- Definition of Stack destructor
template<typename StackElement>
Stack<StackElement>::~Stack()
{     
  // Set pointers to run through the stack
  Stack<StackElement>::NodePointer currPtr = myTop,  // node to be deallocated
    nextPtr;          // its successor
  while (currPtr != 0)
    {
      nextPtr = currPtr->next;
      delete currPtr;
      currPtr = nextPtr;
    }
}

//--- Definition of assignment operator
template<typename StackElement>
Stack<StackElement> & Stack<StackElement>::operator=
                                 (const Stack<StackElement> & original)
{
  myTop = 0;
  if (original.empty()) return *this;

  if (this != &original)               // check that not st = st
    {
      this->~Stack();                   // destroy current linked list
 
      // Copy first node
      myTop = new Stack<StackElement>::Node(original.top());

      // Set pointers to run through the stacks' linked lists
      Stack::NodePointer lastPtr = myTop,
	origPtr = original.myTop->next;

      while (origPtr != 0)
        {
          lastPtr->next = new Stack<StackElement>::Node(origPtr->data);
          lastPtr = lastPtr->next;
          origPtr = origPtr->next;
        } 
    }
  return *this;
}

//--- Definition of empty()
template<typename StackElement>
inline bool Stack<StackElement>::empty() const
{ 
  return (myTop == 0); 
}

//--- Definition of push()
template<typename StackElement>
void Stack<StackElement>::push(const StackElement & value)
{
  myTop = new Stack<StackElement>::Node(value, myTop);
}

//--- Definition of display()
template<typename StackElement>
inline void Stack<StackElement>::display(ostream & out) const
{
  Stack<StackElement>::NodePointer ptr;
  for (ptr = myTop; ptr != 0; ptr = ptr->next)
    out << ptr->data << endl;
}

//--- Definition of top()
template<typename StackElement>
inline StackElement Stack<StackElement>::top() const
{
  if (!empty())
    return (myTop->data);
  else
    {
      cerr << "*** Stack is empty "
	" -- returning garbage ***\n";
      return *(new StackElement);   // "Garbage" value
    }
}

//--- Definition of pop()
template<typename StackElement>
void Stack<StackElement>::pop()
{
  if (!empty())
    {
      Stack<StackElement>::NodePointer ptr = myTop;
      myTop = myTop->next;
      delete ptr;
    }   
  else
    cerr << "*** Stack is empty -- can't remove a value ***\n";
}

#endif 
