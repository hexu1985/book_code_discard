// Listing 6.8. Using pointers for array processing

#include <iostream>
using namespace std;

 int main()
  { 
    char buf[6], data[6], *p, *q; //arrays and pointers
    int i;                        // array index
    p = &buf[0];              // explicit syntax for address
    q = data;                 // implicit syntax for address
    cout << "Initial buffer: ";  
    for (i=0;  i < 6;  i++)  // assign array components
      { p[i] = 'A'+i;         // upper case letters
        cout << p[i];         // display ABCDEF
        q[i] = 'a'+i; }       // q and data are synonyms
    p = &buf[13];             // point to second half of the array
    for (i=0;  i < 3;  i++)  // replace last 13 components
      p[i] = q[i];     // same as buf[i+13]=data[i];
    cout << endl << "Replaced second half: ";
    for (i=0;  i < 6;  i++) 
      cout << buf[i];         // display ABCabc
    p = buf;                  // point to start of ar-ray again
    for (i=0;  i < 3;  i++)  // replace the first half of array
      *(p+i) = *(q+i);        // same as buf[i]=data[i];
    cout << endl << "Replaced first part:  ";
    while (p - buf < 6)      // display with incremented pointer 
      cout << *p++;           // do not overuse this feature
    cout << endl;
    return 0;
  }
