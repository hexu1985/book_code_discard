// Listing 17.3	Reuse of class design for a Stack that contains Point objects

#include <iostream.h> 
#include <stdlib.h>
//#include <iostream> 
//using namespace std;

class Point {
	int x, y;
friend ostream& operator << (ostream& out, const Point& p);
public:
	Point() { }                 // default constructor: empty
	Point(const Point &p)       // copy constructor: for return
	{ x = p.x;  y = p.y; }
	void set(int a, int b)      // set Point coordinates
	{ x = a;  y = b; }
} ;

ostream& operator << (ostream& out, const Point& p)
{ out << "(" << p.x << "," << p.y << ")"; 
  return out; }

template <class Type>
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

template <class Type>
Stack<Type>::Stack(int sz = 100) : size(sz),top(0)
{ items = new Type[sz];         // allocate heap memory
  if (items==0) 
  { cout << "Out of memory\n";  exit(1); } }

template <class T>
void Stack<T>::push (const T& c)
 { if (top < size)              // normal case: push symbol
     items[top++] = c;
   else                         // recover from stack overflow
     { T *p = new T[size*2];          // get more heap memory
       if (p == 0)                    // test for success
	   { cout << "Out of memory\n";  exit(1); } 
       for (int i=0;  i < size;  i++) // copy existing stack
          p[i] = items[i];
       delete [] items;               // return heap memory
       items = p;                     // hook up new memory
       size *= 2;                     // update stack size
       cout << "New size: " << size << endl;
       items[top++] = c; } }          // push symbol on top

template <class Type>
Type Stack<Type>::pop() 
{ return items[--top]; }              // pop unconditionally

template <class Tp>
bool Stack<Tp>::isEmpty() const        // anything to pop?
{ return top == 0; }

template <class Type>
Stack<Type>::~Stack() 
{ delete [] items; }                  // return heap memory

int main()
{   
  Point data[5]; 
  data[0].set(1, 2); data[1].set(3, 4); data[2].set(5, 6); 
  data[3].set(7, 8); data[4].set(9, 0);
  Stack<Point> s(4);                       // stack object
  int n = sizeof(data)/sizeof(Point); // number of components
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
