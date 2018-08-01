#include <iostream>
#include "boost/limits.hpp"

int main() {
  unsigned char c;
  long l=std::numeric_limits<unsigned char>::max()+14;

  c=l;
  std::cout << "c is:       " << (int)c << '\n';
  long reduced=l%(std::numeric_limits<unsigned char>::max()+1);
  std::cout << "reduced is: " << reduced << '\n';
}

