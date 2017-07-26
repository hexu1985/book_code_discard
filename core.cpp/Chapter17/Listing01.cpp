// Listing 17.1	Class Stack that contains characters.

#include <iostream> 
using namespace std;

class Stack {
  char *items;                  // stack of character symbols
  int top, size;                // current top, total size
  Stack(const Stack&);
  operator = (const Stack&);
public:
  Stack(int);                   // conversion constructor
  void push(char);              // push on top of stack
  char pop();                   // pop the top symbol
  bool isEmpty() const;         // is stack empty?
  ~Stack();                     // return heap memory
} ;

Stack::Stack(int sz = 100) : size(sz),top(0)
{ items = new char[sz];         // allocate heap memory
  if (items==0) 
  { cout << "Out of memory\n";  exit(1); } }

void Stack::push (char c)
 { if (top < size)              // normal case: push symbol
     items[top++] = c;
   else                         // recover from stack overflow
     { char *p = new char[size*2];    // get more heap memory
       if (p == 0)                    // test for success
	   { cout << "Out of memory\n";  exit(1); } 
       for (int i=0;  i < size;  i++) // copy existing stack
          p[i] = items[i];
	   delete [] items;               // return heap memory
	   items = p;                     // hook up new memory
	   size *= 2;                     // update stack size
	   cout << "New size: " << size << endl;
       items[top++] = c; } }          // push symbol on top

char Stack::pop() 
{ return items[--top]; }              // pop unconditionally

bool Stack::isEmpty() const           // anything to pop?
{ return top == 0; }

Stack::~Stack() 
{ delete [] items; }                  // return heap memory

int main()
{
  char data[] = "abcdefghij";         // pre-canned input data
  Stack s(4);                         // Stack object
  int n = sizeof(data)/sizeof(char)-1; // input data count
  cout << "Initial data:  ";
  for (int j = 0;  j < n;  j++)       // print initial data
  { cout << data[j] << " "; }
  cout << endl;
  for (int i = 0;  i < n;  i++)       // push data on the stack
    s.push(data[i]);
  cout << "Inversed data: ";
  while (!s.isEmpty())                // pop until stack is empty
    cout << s.pop() << " "; 
  cout << endl;
  return 0;
  }
