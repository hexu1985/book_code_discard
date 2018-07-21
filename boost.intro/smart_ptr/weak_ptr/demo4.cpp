#include <iostream>
#include <string>
#include "boost/shared_ptr.hpp"
#include "boost/weak_ptr.hpp"

void access_the_resource(boost::weak_ptr<std::string> wp) {
  boost::shared_ptr<std::string> sp(wp);
  std::cout << *sp << '\n';
}

int main() {
  boost::shared_ptr<std::string> 
    sp(new std::string("Some resource"));
  boost::weak_ptr<std::string> wp(sp);
  // ...
  access_the_resource(wp);  
}

