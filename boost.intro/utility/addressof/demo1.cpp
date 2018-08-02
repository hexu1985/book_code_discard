#include "boost/utility.hpp"

class some_class {};

int main() {
  some_class s;
  some_class* p=boost::addressof(s);
}

