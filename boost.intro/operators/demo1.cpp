#include <iostream>
#include "boost/operators.hpp"

class some_class : boost::equivalent<some_class> {
  int value_;
public:
  some_class(int value) : value_(value) {}

  bool less_than(const some_class& other) const {
    return value_<other.value_;
  }
};

bool operator<(const some_class& lhs, const some_class& rhs) {
  return lhs.less_than(rhs);
}

int main() {
  some_class s1(12);
  some_class s2(11);

  if (s1==s2) 
    std::cout << "s1==s2\n";
  else
    std::cout << "s1!=s2\n";
}

