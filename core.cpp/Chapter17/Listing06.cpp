// Listing 17.6	Example of a template class specialization.

#include <iostream> 
using namespace std;

template <class T>
class Array {
  T *data;                      // heap array of data
  int size;                     // size of the array
  Array(const Array&);
  operator = (const Array&);
public:
  Array(T items[], int n) : size(n)      // conversion constructor
  { data = new T[n];           // allocate heap memory
    if (data==0) 
	{ cout << "Out of memory\n";  exit(1); } 
    for (int i=0;  i < n;  i++)
      data[i] = items[i]; }
  int find (const T& val) const
  { for (int i = 0;  i < size;  i++)
	  if (val == data[i])
		  return i; 
    return -1; }
  ~Array()
  { delete [] data; }   
 } ;

template <>                         // empty template list
class Array <char *> {              // type of specialization
  char* *data;                      // heap array of data
  int size;                         // size of the array
  Array(const Array&);
  operator = (const Array&);
public:
  Array(char* items[], int n) : size(n)      // conversion 
  { data = new char*[n];           // allocate heap memory
    if (data==0) 
	{ cout << "Out of memory\n";  exit(1); } 
    for (int i=0;  i < n;  i++)
	{ int len = strlen(items[i]); // special for strings only
	  data[i] = new char[len+1];
	strcpy(data[i],items[i]); } }
  int find (const char*& val) const
  { for (int i = 0;  i < size;  i++)
      if (strcmp(val,data[i])==0)    // special for strings only
		return i;
    return -1; }
  ~Array()
  { delete [] data; }   
 } ;

int main()
{ 
  int data1[] = { 1, 2, 3, 4, 5 } ;
  char* data2[] = { "one", "two", "three", "four", "five" } ;
  int n1 = sizeof(data1)/sizeof(int); // number of components
  int n2 = sizeof(data2)/sizeof(char*); 
  cout << "Initial data:  ";
  for (int j = 0;  j < n1;  j++)     
  { cout << data1[j] << " "; }        // print input data
  cout << endl;
  for (int i = 0;  i < n2;  i++)     
  { cout << data2[i] << " "; }        // print input data
  cout << endl;
  Array<int> a1(data1,n1);            // array object
  Array<char*> a2(data2,n2);          // specialized object
  int item1 = 3;  int idx;
  char* item2 = "three";
  if ((idx = a1.find(item1)) != -1)
	cout << "Item " << item1 <<" is at index " << idx << endl;
  if ((idx = a2.find(item2)) != -1)
	cout << "Item " << item2 <<" is at index " << idx << endl;  
  return 0;
  }

