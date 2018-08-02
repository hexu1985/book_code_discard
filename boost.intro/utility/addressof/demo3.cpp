#include "boost/utility.hpp"
#include <iostream>

class codebreaker {
public:
  int operator&() const {
    return 13;
  }
};

template <typename T> void print_address(const T& t) {
  std::cout << "Address: " << (&t) << '\n';
  std::cout << "addressof(t): " << boost::addressof(t) << '\n';
}

int main() {
  codebreaker c;
  print_address(c);
}

