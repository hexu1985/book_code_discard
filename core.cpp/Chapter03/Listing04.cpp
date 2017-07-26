// Listing 3.4.	An example of manipulating character values

#include <iostream>
using namespace std;

int main(void)
{ char ch;  int cnt;
  ch = 65; cnt = 0;                                         // ch contains 'A'
  while (cnt < 26)
    { cout << ch;
      ch = ch + 1; cnt = cnt + 1; }
  cout << endl;
  ch = 'a' - 1;                                             // ch contains character '`'
  while (ch < 'z')
    { ch = ch + 1;                                          // ch contains 'a', 'b', ... 'z'
      cout << ch; }
  cout << endl;
  cout << "Single \' and double \" quotes are special\n";    // new line: same as endl
  cout << "And so is the escape character \\" << endl;
  return 0;
    }
