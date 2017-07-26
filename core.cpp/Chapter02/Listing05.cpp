// Listing 2-5. An interactive program with input and output statements

#include <iostream>            // a different library
using namespace std;

int main(void)
{ 
  int a, b, c;                                        // definitions of variables
  cout << "Type two integers, press Enter ";          // no printf()string output: inser-tion
  cin >> a >> b;                                      // two function calls:       // ex-traction
  c = a + b;  
  cout << "Their sum is " << c << endl;             // insertion with new line at end
  return 0;
}
