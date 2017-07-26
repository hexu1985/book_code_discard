// Listing 16.7	Using an Array class as a container for integer components.

#include <iostream>   
using namespace std;

class Array {
public:
  int size;                  // number of valid components
  int *ptr;                  // pointer to array of components
  void set(const int* a, int n);  // allocate/init heap memory
public:
  Array (const int* a,int n); // general constructor
  Array (const Array &s);     // copy constructor
 ~Array();                    // return heap memory
  Array& operator = (const Array& a); // copy array to another
  int getSize() const;
  int getInt(int i) const;    // return the i-th component
  void setInt(int i, int x);  // set int x at position i
 } ;

 void Array::set(const int* a, int n)
 { size = n;                    // evaluate array size
   ptr = new int[size];         // request heap memory
   if (ptr == 0) { cout << "Out of memory\n"; exit(0); }  
   for (int i=0;  i < size;  i++)
	   ptr[i] = a[i]; }         // copy client data to heap

Array::Array (const int* a, int n)     // general
 { set(a,n); }

Array::Array (const Array &a)   // copy constructor
 { set(a.ptr,a.size); }
  
Array::~Array()                 // destructor
 { delete [ ] ptr; }

Array& Array::operator = (const Array& a)
{ if (this == &a) return *this; // no work if self-assignment
  delete [ ] ptr;               // return existing memory
  set(a.ptr,a.size);            // allocate/set new memory
  return *this; }               // to support chain assignment

int Array::getSize() const      // get array size
{ return size; }

int Array::getInt (int i) const // object does not change
{ if (i < 0 || i >= size)       // index is out of bounds
    return ptr[size-1];         // return the last component
  return ptr[i]; }              // legal index: return value

void Array::setInt(int i,int x) // modify Array object
{ if (i < 0 || i >= size)       // check if index is legal
    return;                     // no op if it is out of bounds
  ptr[i] = x; }                 // legal index: set the value

int main()
{ 
  int arr[] = { 1,3,5,7,11,13,17,19 } ;   // data to process
  Array a(arr, 8);                        // create the object
  int size = a.getSize();           // get array size
  for (int i=0;  i < size;  i++)    // go over each component
  { cout << " " << a.getInt(i); }   // print next component
  cout << endl << endl;
  for (int j=0;  j < size;  j++)    // go over the array again
   { int x = a.getInt(j);           // get next component
     a.setInt(j, 2*x); }            // update the value
  for (int k = 0;  k < size;  k++)
  { cout << " " << a.getInt(k); }   // print updated array
  cout << endl;
  return 0;
  }
