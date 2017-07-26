// Listing 5.13. Using union to store values of different types in a variable

#include <iostream>  
#include "number.h"      // to make type Number known to compiler
#include <cstring> 
using namespace std;

int main ()
{ 
  Number num[6];  int i = 0;          // array of union variables
  num[0].value = 11.0; num[1].value = 21.0;     // initialization
  num[2].value = 31.0; strcpy(num[3].text,"end"); 
  while(strcmp(num[i].text, "end") != 0)        // iteration
    cout << num[i++].value << endl;
  cout << num[i].text << endl;        // for illustration purposes
  cout << "Text as double: " << num[i].value << endl; // same goal
  return 0;
  }
