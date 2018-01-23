/*-------------------------------------------------------------------------
  Program to implement a copy command.  If it is compiled and saved under
  the name copy, a command of the form
                          copy file1 file2
  will copy the contents of file1 to file2.
 
  Receive:      A sequence of command-line strings
  Input(file):  A text file
  Output(file): Contents of the text file
-------------------------------------------------------------------------*/

#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

int main(int argc, char * argv[])
{
  if (argc != 3)
    cerr << "Usage:  copy file1 file2 \n\n";
  else
  {
    ifstream in(argv[1]);
    assert (in.is_open());
    ofstream out(argv[2]);
    assert (out.is_open());
    char ch;
    while (!in.eof())
    {
      in.get(ch);
      out.put(ch);
    }
    cout << "File copy completed\n\n";
  }
}
