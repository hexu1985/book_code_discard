#include <iostream>
#include "boost/limits.hpp"
#include "boost/cast.hpp"

int main() {
  unsigned int ui=std::numeric_limits<unsigned int>::max();
  int i;

  try {
    std::cout << "Assignment from unsigned int to signed int\n";
    i=boost::numeric_cast<int>(ui);
  }
  catch(boost::bad_numeric_cast& e) {
    std::cout << e.what() << "\n\n";
  }

  try {
    std::cout << "Assignment from signed int to unsigned int\n";
    i=-12;
    ui=boost::numeric_cast<unsigned int>(i);
  }
  catch(boost::bad_numeric_cast& e) {
    std::cout << e.what() << "\n\n";
  }
}

