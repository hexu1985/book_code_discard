#include <regex>
#include <string>
using std::regex;
using std::string;

int main()
{ // demonstrate basic_regex assignment operators
  regex rgx;                   // empty regular expression object
  rgx = "abc";                 // holds  "abc", ECMAScript encoding
  string str("[def]");
  rgx = str;                   // holds  "[def]", ECMAScript encoding
  regex rgx1("abc [def]", regex::basic);
  rgx = rgx1;              // holds  "abc[def]", BRE encoding
  return 0;
}



