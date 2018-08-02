#include <iostream>
#include "boost/utility/enable_if.hpp"
#include "boost/type_traits.hpp"

void some_func(int i) {
  std::cout << "void some_func(" << i << ")\n";
}

template <typename T> void some_func(
  T t,typename boost::disable_if<
    boost::is_integral<T> >::type* p=0) {
    typename T::type variable_of_nested_type;
    std::cout << "template <typename T> void some_func(T t)\n";
}

class some_class {
public:
  typedef int type;
};

int main() {
  int i=12;
  short s=12;

  some_func(i);
  some_func(s);
  some_func(some_class());
}


