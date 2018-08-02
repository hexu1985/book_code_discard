#include <iostream>
#include <string>
#include <limits>
#include "boost/utility/enable_if.hpp"
#include "boost/type_traits.hpp"

// Definition of the template some_class omitted
template <typename T,typename Enable=void> class some_class {
public:
  int max() const {
    std::cout << "some_class::max() for the primary template\n";
    return std::numeric_limits<int>::max();
  }
};

template <typename T> class some_class<T,
  typename boost::enable_if<boost::is_arithmetic<T> >::type> {
public:
  T max() const {
   std::cout << "some_class::max() with an arithmetic type\n";
   return std::numeric_limits<T>::max();
  }
};

int main() {
  std::cout << "Max for std::string: " <<
    some_class<std::string>().max() << '\n';
  std::cout << "Max for void: " << 
    some_class<void>().max() << '\n';
  std::cout << "Max for short: " << 
    some_class<short>().max() << '\n';
  std::cout << "Max for int: " << 
    some_class<int>().max() << '\n';
  std::cout << "Max for long: " << 
    some_class<long>().max() << '\n';
  std::cout << "Max for double: " << 
    some_class<double>().max() << '\n';
}

