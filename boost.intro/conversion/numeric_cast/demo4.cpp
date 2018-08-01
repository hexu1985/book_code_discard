#include <iostream>
#include "boost/limits.hpp"
#include "boost/cast.hpp"

int main() {
  double d=127.123456789123456;
//  double d=128.123456789123456;
  char c;
  std::cout << "char type maximum: ";
  std::cout << (int)std::numeric_limits<char>::max() << "\n\n";
  
  c=d;
  std::cout << "Assignment from double to char: \n";
  std::cout << "double: " << d << "\n";
  std::cout << "char:   " << (int)c << "\n";
  
  std::cout << "Trying the same thing with numeric_cast:\n";
  
  try {
    c=boost::numeric_cast<char>(d);
    std::cout << "double: " << d;
    std::cout << "char:   " << (int)c;
  }
    catch(boost::bad_numeric_cast& e) {
      std::cout << e.what();
  }

  return 0;
}

