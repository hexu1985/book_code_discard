/*-- DStackT.h -------------------------------------------------------------
  This header file defines a template for a Stack data type.  
  StackElement is a type parameter received from a client program.
  Basic operations:
    constructor:      Constructs an empty stack
    copy constructor: Makes a copy of a stack
    destructor:       Deallocates memory allocated by constructor
    = :               Assignment operator
    empty:            Checks if a stack is empty
    push:             Modifies a stack by adding a value at the top
    top:              Accesses the top stack value; leaves stack unchanged
    pop:              Modifies stack by removing the value at the top
    << and display:   Displays all the stack elements

  Class Invariant:
    1. The stack elements (if any) are stored in positions
       0, 1, . . ., myTop of myArray.
    2. -1 <= myTop < myCapacity 
--------------------------------------------------------------------------*/

#include <iostream>
#include <cassert>

#ifndef DSTACKT
#define DSTACKT

template <typename StackElement>
class Stack
{
 public:
 /***** Function Members *****/
 /***** Constructors *****/

  Stack(int numElements = 128);
  /*------------------------------------------------------------------------
    Construct a Stack object.

    Precondition:  None.
    Postcondition: An empty Stack object has been constructed (myTop is 
        initialized to -1 and myArray is an array with numElements
        (default 128) elements of type StackElement).
   -----------------------------------------------------------------------*/

  Stack(const Stack<StackElement> & original);
  /*------------------------------------------------------------------------
    Copy Constructor 

    Precondition:  original is the stack to be copied and is received as 
        a const reference parameter.
    Postcondition: A copy of original has been constructed.
  ------------------------------------------------------------------------*/

 /***** Destructor *****/
  ~Stack(); 
  /*-----------------------------------------------------------------------
    Class destructor 

    Precondition:  None
    Postcondition: The dynamic array in the stack has been deallocated.
  ------------------------------------------------------------------------*/

 /***** Assignment *****/
  const Stack<StackElement> & operator=(
                        const Stack<StackElement> & rightHandSide);
  /*------------------------------------------------------------------------
    Assignment Operator 
    Precondition:  rightHandSide is the stack to be assigned
        and is received as a const reference parameter.
    Postcondition: The current stack becomes a copy of rightHandSide
        and a const reference to it is returned.
  ------------------------------------------------------------------------*/

  bool empty() const;
  /*------------------------------------------------------------------------
    Check if stack is empty.
    Precondition:  None
    Postcondition: Returns true if stack is empty and false otherwise.
   -----------------------------------------------------------------------*/

  void push(const StackElement & value);
  /*------------------------------------------------------------------------
    Add a value to a stack.

    Precondition:  value is to be added to this stack
    Postcondition: value is added at top of stack provided there is space;
         otherwise, a stack-full message is displayed and execution is
         terminated.
   -----------------------------------------------------------------------*/

  void display(ostream & out) const;
  /*------------------------------------------------------------------------
    Display values stored in the stack. 

    Precondition:  ostream out is open.
    Postcondition: Stack's contents, from top down, have been output to out.
   -----------------------------------------------------------------------*/

  StackElement top() const;
  /*------------------------------------------------------------------------
    Retrieve value at top of stack (if any).

    Precondition:  Stack is nonempty
    Postcondition: Value at top of stack is returned, unless the stack is 
        empty; in that case, an error message is displayed and a "garbage
        value" is returned.
   -----------------------------------------------------------------------*/

  void pop();
  /*------------------------------------------------------------------------
    Remove value at top of stack (if any).

    Precondition:  Stack is nonempty.
    Postcondition: Value at top of stack has been removed, unless the 
        stack is empty; in that case, an error message is displayed and
        execution allowed to proceed.
   -----------------------------------------------------------------------*/  

 private:
 /***** Data Members *****/
  int myCapacity,           // capacity of stack
      myTop;                // top of stack
  StackElement * myArray;   // dynamic array to store elements

}; // end of class declaration

//====== FUNCTION DEFINITIONS ======
#include <new>

//--- Definition of Stack constructor
template <typename StackElement>
Stack<StackElement>::Stack(int numElements)
{
   assert (numElements > 0);  // check precondition
   myCapacity = numElements;  // set stack capacity
                              // allocate array with this capacity
   myArray = new(nothrow) StackElement[myCapacity];
   if (myArray != 0)          // memory available
      myTop = -1;
   else
   {
      cerr << "Inadequate memory to allocate stack \n"
              " -- terminating execution\n";
      exit(1);
   }                          // or assert(myArray != 0);
}

//--- Definition of Stack copy constructor
template <typename StackElement>
Stack<StackElement>::Stack(const Stack<StackElement> & original)
: myCapacity(original.myCapacity), myTop(original.myTop)
{
   //--- Get new array for copy
   myArray = new(nothrow) StackElement[myCapacity];  
   if (myArray != 0)                 // check if memory available
      // copy original's array member into this new array
      for (int pos = 0; pos <= myTop; pos++) 
         myArray[pos] = original.myArray[pos];
   else
   {
      cerr << "*Inadequate memory to allocate stack ***\n";
      exit(1);
   }
}

//--- Definition of Stack destructor
template <typename StackElement>
inline Stack<StackElement>::~Stack()
{ 
   delete[] myArray;
}

//--- Definition of assignment operator
template <typename StackElement>
const Stack<StackElement> & Stack<StackElement>::
                      operator=(const Stack<StackElement> & rightHandSide)
{
   if (this != &rightHandSide)                // check that not st = st
   {
      //-- Allocate a new array if necessary
      if (myCapacity != rightHandSide.myCapacity) 
      {
         delete[] myArray;                    // destroy previous array

         myCapacity = rightHandSide.myCapacity;  // copy myCapacity 
         myArray = new StackElement[myCapacity]; 
         if (myArray == 0)                    // check if memory available
         {
            cerr << "*** Inadequate memory ***\n";
            exit(1);
         }
        }

      myTop = rightHandSide.myTop;            // copy myTop member
      for (int pos = 0; pos <= myTop; pos++)  // copy stack elements
         myArray[pos] = rightHandSide.myArray[pos];

   }
   return *this;
}

//--- Definition of empty()
template <typename StackElement>
inline bool Stack<StackElement>::empty() const
{ 
   return (myTop == -1); 
}

//--- Definition of push()
template <typename StackElement>
inline void Stack<StackElement>::push(const StackElement & value)
{
   if (myTop < myCapacity - 1)      //Preserve stack invariant
   { 
      ++myTop;
      myArray[myTop] = value;
   }
   else
   {
      cerr << "*** Stack full -- can't add new value ***\n"
              "Must increase Stack's capacity\n";
      exit(1);
   }
}

//--- Definition of display()
template <typename StackElement>
inline void Stack<StackElement>::display(ostream & out) const
{
  for (int i = myTop; i >= 0; i--) 
    out << myArray[i] << endl;
}

//--- Definition of operator<<()
template <typename StackElement>
inline ostream & operator<<(ostream & out, 
                            const Stack<StackElement> & st)
{
   st.display(out);
   return out;
}

//--- Definition of top()
template <typename StackElement>
inline StackElement Stack<StackElement>::top() const
{
   if ( !empty() ) 
      return (myArray[myTop]);
   else
   {
      cerr << "*** Stack is empty -- returning garbage value ***\n";
      StackElement garbage;
      return garbage;
   }
}

//--- Definition of pop()
template <typename StackElement>
inline void Stack<StackElement>::pop()
{
  if (myTop >= 0)    // Preserve stack invariant
    myTop--;
  else
    cerr << "*** Stack is empty -- can't remove a value ***\n";
}

#endif
