#include <iostream>
#include <string>
#include "boost/shared_ptr.hpp"
#include "boost/weak_ptr.hpp"

int main() {
  boost::shared_ptr<std::string> 
    sp(new std::string("Some resource"));
  boost::weak_ptr<std::string> wp(sp);
  // ...
  if (boost::shared_ptr<std::string> p=wp.lock())
    std::cout << "Got it: " << *p << '\n';
  else
    std::cout << "Nah, the shared_ptr is empty\n";
}

