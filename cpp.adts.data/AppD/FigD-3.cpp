/*-------------------------------------------------------------------------
  Program to demonstrate main parameters argc and argv.
 
  Receive: A sequence of command-line strings
  Output:  The value of argc, followed by each string in argv
-------------------------------------------------------------------------*/

#include <iostream>
using namespace std;

int main(int argc, char * argv[])
{
   cout << "There are " << argc 
        << "strings on the command line:\n";
   for (int i = 0; i < argc; i++)
      cout << "   argv[" << i << "] = "  << argv[i] << endl;
}
