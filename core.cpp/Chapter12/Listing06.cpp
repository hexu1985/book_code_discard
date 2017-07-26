// Listing 12.6	A container class with fixed size of component array and an iterator.

#include <iostream> 
using namespace std;

class Sample {                        // component class
  double value;                       // sample value
public:
  Sample (double x = 0)   // default and conversion constructor
    { value = x; } 
  void set (double x)                 // modifier method
    { value = x; }
 double get () const                  // selector method
    { return value; } } ;

 class History {                  // container class: set value
  enum { size = 8 };
  Sample data[size];              // fixed-size array of samples
  int count;                      // number of valid elements
  int idx;                        // index of the current sample
public:
  History() : count(0), idx(0) { } // make array empty
  void add(double);                // add a sample at the end
  Sample& getComponent()           // return reference to Sample
  { return data[idx]; }            // can be a message target
  void getFirst() 
  { idx = 0; }                     // set to start of data set
  bool getNext()
  { return ++idx < count; }        // move to next element in set
  void average () const;           // print average
} ;

void History::add(double s)
{ if (count < size)
    data[count++].set(s); }        // or just:  data[i++] = s; 

void History::average () const
{ cout << "\n Average value: ";
  double sum = 0;
  for (int i = 0;  i < count;  i++)
	sum += data[i].get();
  cout << sum/count << endl; }

int main()
{ double a[] = {3, 5, 7, 11, 13, 17, 19, 23, 29 } ; // input data
  History h;                              // default constructor
  for (int i=0; i < 9;  i++)
    h.add(a[i]);                                 // add history
  cout << "\n Measurement history:" << endl << endl;  
  h.getFirst();                           // work is pushed up
  do { 
     cout << "  " << h.getComponent().get(); // print components
    } while (h.getNext());
  h.average();  
  return 0;
  }

