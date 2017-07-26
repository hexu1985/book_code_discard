#include <regex>
#include <string>
using std::regex;
using std::string;

int main ()
{ // demonstrate basic regex constructors
  regex rgx0;         // default constructor; matches nothing
  char expr1[] = "abc[d-f]";
  regex rgx1(expr1);   // holds "abc[d-f]", ECMAScript grammar
  regex rgx2(expr1, 3); // holds "abc", ECMAScript grammar
  regex rgx3(rgx2);   // holds "abc", ECMAScript grammar
  string str("[def]");
  regex rgx4(str, regex ::basic);
              // holds "[def]", BRE grammar
  regex rgx5(str.begin(), str.end(),
    regex::basic | regex::icase);
              // holds "[def]", BRE grammar,
              // case insensitive
  return 0;
}



