#include <iostream>

template <typename Derived> class equivalent {
public:
  friend bool operator==(const Derived& lhs,const Derived& rhs) {
    return !(lhs<rhs) && !(rhs<lhs);
  }
};

class some_class : equivalent<some_class> {
  int value_;
public:
  some_class(int value) : value_(value) {}
  friend bool operator<(const some_class& lhs,
    const some_class& rhs) {
    return lhs.value_<rhs.value_;
  }
};

int main() {
  some_class s1(4);
  some_class s2(4);

  if (s1==s2)
    std::cout << "s1==s2\n";
}

