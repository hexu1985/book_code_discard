// Listing 12.5	A container class with fixed size of component array and overflow control.

#include <iostream> 
using namespace std;

class Sample {                         // component class
  double value;                        // sample value
public:
  Sample (double x = 0)   // default and conversion constructor
    { value = x; } 
  void set (double x)                  // modifier method
    { value = x; }
 double get () const                   // selector method
    { return value; } } ;

class History {                    // container class: set value
  enum { size = 8 };
  Sample data[size];               // fixed-size array of samples
  int idx;                         // index of current sample
public:
  History() : idx(0) { }           // make array empty initially
  void add(double);                // add a sample at the end
  void print () const;             // print history
  void average () const;           // print average
 } ;

void History::add(double s)
{ if (idx < size)
    data[idx++].set(s); }          // or just:  data[idx++] = s; 

void History::print () const
{ cout << "\n Measurement history:" << endl << endl;
  for (int i = 0;  i < size;  i++)            // local index
    cout << "  " << data[i].get(); }

void History::average () const
{ cout << "\n Average value: ";
  double sum = 0;                             // local tally
  for (int i = 0;  i < size;  i++)            // local index
    sum += data[i].get();
  cout << sum/size << endl; }

int main()
{ double a[] = {3, 5, 7, 11, 13, 17, 19, 23, 29 } ; // input data
  History h;                             // default constructor
  for (int i=0; i < 9;  i++)     // it is protected from overflow
    h.add(a[i]);                         // add history
  h.print();                             // print history
  h.average();                           // print average
  return 0;
  }

