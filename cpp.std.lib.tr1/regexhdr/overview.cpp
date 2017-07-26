#include <regex>
#include <iostream>
#include <string>
using std::regex;
using std::cmatch; using std::regex_search;
using std::cout ; using std::string;

int main ()
{
  string str("\\.a");
  regex  rgx(str);
  cmatch match;
  if (std::regex_search("aba.a", match, rgx))
    std::cout << "match found after "
      << match.prefix() << '\n';
  return 0;
}



