#include "boost/utility.hpp"

class please_dont_make_copies : boost::noncopyable {};

int main() {
  please_dont_make_copies d1;
  please_dont_make_copies d2(d1);
  please_dont_make_copies d3;
  d3=d1;
}

