// Listing 12.4	A container class with fixed size component array (and array overflow).

#include <iostream> 
using namespace std;


class Sample {                               // component class
  double value;                                 // sample value
public:
  Sample (double x = 0)    // default and conversion constructor
    { value = x; } 
  void set (double x)                 // modifier method
    { value = x; }
 double get () const                  // selector method
    { return value; } } ;

 class History {                              // container class
  enum { size = 8 };
  Sample data[size];        // fixed-size array of samples
public:
  void set(double, int);                      // modify a sample
  void print () const;                        // print history
  void average () const;                      // print average
 } ;

void History::set(double s, int i)
{ data[i].set(s); }                   // or just:  data[i] = s; 

void History::print () const                  // print history
{ cout << "\n Measurement history:" << endl << endl;
  for (int i = 0;  i < size;  i++)            // local index
    cout << "  " << data[i].get(); }

void History::average () const
{ cout << "\n Average value: ";               // print average
  double sum = 0;                             // local value
  for (int i = 0;  i < size;  i++)            // local index
	sum += data[i].get();
  cout << sum/size << endl; }
 
int main()
{ double a[] = {3, 5, 7, 11, 13, 17, 19, 23, 29 } ; // input data
  History h;                             // default constructor
  for (int i=0; i < 9;  i++)             // 8 slots are available
    h.set(a[i],i);                            // set history
  h.print();                                  // print history
  h.average();                                // compute average
  return 0;
  }

