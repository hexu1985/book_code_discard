#include "boost/checked_delete.hpp"

class some_class;

some_class* create() {
  return (some_class*)0;
}

int main() {
  some_class* p=create();
  boost::checked_delete(p);
  //delete p;
}

