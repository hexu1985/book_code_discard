#include <regex>
using std::regex;

int main()
{ // demonstrate use of swap
  regex rgx0;            // empty regular expression object
  regex rgx1("abc");     // holds  "abc"
  rgx0.swap(rgx1);      // rgx0 holds  "abc" and rgx1 is empty
  swap(rgx0, rgx1);       // rgx0 is empty and rgx1 holds  "abc"
  return 0;
}

