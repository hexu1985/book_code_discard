// Listing 17.5	Example of a template class with a nested server class.

#include <iostream> 
using namespace std;

template <class T>
class Stack {
    struct Node {               // it depends on parameter type
        T item;                         // same type as in Stack
        Node *next;             // Node<T> is incorrect here
        Node(const T& val) : item(val)  // same type as in Stack
		{ next = NULL; } } ;
  Node *top;                    // it is not a template now
public:
  Stack()                       // default: no initial length
  { top = NULL; }
  void push(const T&);
  T pop();
  int isEmpty() const    
  { return top == NULL; }       // does top point to a node?
  ~Stack();
 } ;

template <class T>
void Stack<T>::push (const T& val)
// { Node<T> *p = new Node<T>(val); // type Node<T>, not Node
 { Node *p = new Node(val);         // type Node, not Node<T>
   if (p == NULL)
    { cout << "Out of memory\n";  exit(1); }
   p->next = top;                   // point it to first node
   top = p; }                       // point it to new node
 
template <class T>
T Stack<T>::pop()                   // return value of type T
// { Node<T> *p = top;              // type Node<T>, not Node
 { Node *p = top;                   // type Node, not Node<T>
   T val = top->item;               // get the value of type T
   top = top->next;                 // point to the second node
   delete p;                        // return top node to heap
   return val; }

template <class T>  
Stack<T>::~Stack()
// { Node<T> *p = top;              // type Node of type T
 { Node *p = top;                   // type Node of type T
   while (top != NULL)              // top is 0 when no nodes
     { top = top->next;             // point to the next node
       delete p;                    // delete the previous node
       p = top; } }                 // traverse to the next node
 
int main()
{ 
  int data[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 } ;
  Stack<int> s;                       // stack object
  int n = sizeof(data)/sizeof(int);   // number of components
  cout << "Initial data:  ";
  for (int j = 0;  j < n;  j++)     
    { cout << data[j] << " "; }       // print input data
  cout << endl;
  for (int i = 0;  i < n;  i++)
    { s.push(data[i]); }              // push data on the stack
  cout << "Inversed data: ";
  while (!s.isEmpty())                // pop until stack is empty
    cout << s.pop() << " ";
  cout << endl;
  return 0;
  }
