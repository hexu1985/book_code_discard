// Listing 6.4. Communicating with another file through external declara-tions (Part 2 of 2)

#include <iostream>
using namespace std;
 extern count;                    // defined and initialized else-where
 extern char caption[];     // defined and initialized elsewhere
 
 void printCaption()              // called from this file only
 { cout << caption; }
 
 void printAverage(double sum)    // called from another file
 { if (count == 0) return;
   printCaption();
   cout << sum/count << endl;
  }
