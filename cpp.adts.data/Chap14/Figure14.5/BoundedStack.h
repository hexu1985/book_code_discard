#include <iostream>
#include "LStackT.h"       // A linked-list based version of our
                           // stack class template from Section 8.3
#ifndef BOUNDED_STACK
#define BOUNDED_STACK
template <typename ElementType>
class BoundedStack : public Stack<ElementType>
{
 public:
  /***** Function Members *****/
  BoundedStack(int limit = 0);
  /* --- Constructor ------------------------------------------------------
    Precondition:  limit (default 0) is an upper bound on the size of the
        bounded stack.
    Postcondition: A BoundedStack has been constructed as an empty stack
        with mySize initialized to 0 and myLimit initialized to limit
        (default 0).
   -----------------------------------------------------------------------*/

  void push(const ElementType & value);
  /*--- Add a value to the stack if there is room -------------------------
    Precondition:  None. 
    Postcondition: value was added at the top of this BoundedStack and
        mySize was incremented by 1 provided there was room; if there 
        wasn't, an overflow message was displayed.
   -----------------------------------------------------------------------*/

 private:
  /***** Data Members *****/
   int mySize,
       myLimit;
};  // end of class template declaration

//--- Definition of Constructor ---
template <typename ElementType>
inline BoundedStack<ElementType>::BoundedStack(int limit)
: Stack<ElementType>(), mySize(0), myLimit(limit)
{ }

//--- Definition of push() ---
template <typename ElementType>
inline void BoundedStack<ElementType>::push(const ElementType & value)
{
  if (mySize < myLimit)
  {
    Stack<ElementType>::push(value);
    mySize++;
  }
  else
    cerr << "*** Bounded stack overflow ***\n";
}

#endif
