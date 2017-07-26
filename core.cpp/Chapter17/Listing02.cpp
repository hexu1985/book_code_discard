// Listing 17.2	Reuse of class design for a Stack that contains integers

#include <iostream> 
using namespace std;

typedef int Type;               // portable type definition

class Stack {
  Type *items;                  // stack of items of type Type
  int top, size;                // current top, total size
  Stack(const Stack&);
  operator = (const Stack&);
public:
  Stack(int);                   // conversion constructor
  void push(const Type&);       // push on top of stack
  Type pop();                   // pop the top symbol
  bool isEmpty() const;         // is stack empty?
  ~Stack();                     // return heap memory
} ;

Stack::Stack(int sz = 100) : size(sz),top(0)
{ items = new Type[sz];         // allocate heap memory
  if (items==0) 
  { cout << "Out of memory\n";  exit(1); } }

void Stack::push (const Type& c)      // pass by reference
 { if (top < size)              // normal case: push symbol
     items[top++] = c;
   else                         // recover from stack overflow
     { Type *p = new Type[size*2];    // get more heap memory
       if (p == 0)                    // test for success
	   { cout << "Out of memory\n";  exit(1); } 
       for (int i=0;  i < size;  i++) // copy existing stack
          p[i] = items[i];
       delete [] items;            // return heap memory
       items = p;                  // hook up new memory
       size *= 2;                  // update stack size
       cout << "New size: " << size << endl;
       items[top++] = c; } }          // push symbol on top

Type Stack::pop() 
{ return items[--top]; }              // pop unconditionally

bool Stack::isEmpty() const           // anything to pop?
{ return top == 0; }

Stack::~Stack() 
{ delete [] items; }                  // return heap memory

int main()
{
  Type data[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 } ;
  Stack s(4);                         // stack object
  int n = sizeof(data)/sizeof(Type);  // input data count
  cout << "Initial data:  ";
  for (int j = 0;  j < n;  j++)     
   { cout << data[j] << " "; }        // print input data
  cout << endl;
  for (int i = 0;  i < n;  i++)
   { s.push(data[i]); }               // push data on the stack
  cout << "Inversed data: ";
  while (!s.isEmpty())                // pop until stack is empty
    cout << s.pop() << " ";
  cout << endl;
  return 0;
  }
