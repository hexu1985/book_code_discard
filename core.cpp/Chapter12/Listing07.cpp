// Listing 12.7	A container class with dynamically-allocated memory

#include <iostream> 
using namespace std;

#include <iostream>      // dynamic container of variable size
using namespace std;

class Sample {                               // component class
  double value;                              // sample value
public:
  Sample (double x = 0)  // default and conversion constructor
    { value = x; } 
  void set (double x)                 // modifier method
    { value = x; }
 double get () const                  // selector method
    { return value; } } ;

 class History {                   // container class: set value
  int size, count, idx;
  Sample *data;
 public:
  History() : size(3), count(0), idx(0)  // make array empty
  { data = new Sample[size];             // allocate new space
    if (data == NULL)       
	{ cout << " Out of memory\n";  exit(1); } }
  void add(double);                 // add a sample at the end
  Sample& getComponent()           // return reference to Sample
  { return data[idx]; }            // can be a message target
  void getFirst() 
  { idx = 0; }
  bool getNext()
  { return ++idx < count; }
  void average () const;               // print average
  ~History() { delete [ ] data; }      // return dynamic memory
} ;

void History::add(double s)
{ if (count == size)
  { size = size * 2;              // double size if out of space
	Sample *p = new Sample[size];
    if (p == NULL)       
	{ cout << " Out of memory\n";  exit(1); }   // test for success
    for (int i=0;  i < count;  i++)
	p[i] = data[i];               // copy existing elements
    delete [ ] data;                 // delete existing array
    data = p;                        // replace it with new array
    cout << " new size: " << size << endl; }  // debugging print
   data[count++].set(s); }           // use next space available

void History::average () const
{ cout << "\n Average value: ";
  double sum = 0;
  for (int i = 0;  i < count;  i++)
	sum += data[i].get();
  cout << sum/count << endl; }

int main()
{ double a[] = {3, 5, 7, 11, 13, 17, 19, 23, 29 } ; // input data
  History h;               
  for (int i=0; i < 9;  i++)
    h.add(a[i]);                                // add history
  cout << "\n Measurement history:" << endl << endl;  
  h.getFirst();                       // work is pushed up
  do {               
     cout << "  " << h.getComponent().get();           // print each component
    } while (h.getNext());
  h.average();
  return 0;
  }

