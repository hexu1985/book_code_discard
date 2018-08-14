#include <cassert>
#include <string>
#include "boost/operators.hpp"

// Definition of class thing omitted
class thing : 
  boost::less_than_comparable<thing>,
  boost::equivalent<thing> {

  std::string name_;
public:
  thing() {}
  explicit thing(const std::string& name):name_(name) {}

  friend bool operator<(const thing& lhs,const thing& rhs) {
    return lhs.name_<rhs.name_;
  } 
};

int main() {
  thing a("First");
  thing b("Second");
  thing c("Third");

  // assert that a<b<c 
  assert(a<b && a<c && !(b<a) && b<c && !(c<a) && !(c<b));

  // 等价关系
  thing x=a;
  assert(!(x<a) && !(a<x));

  // 自反性
  assert(!(a<a));

  // 反对称性
  assert((a<b)==!(b<a));

  // 传递性
  assert(a<b && b<c && a<c);

  // 等价关系的传递性
  thing y=x;
  assert( (!(x<a) && !(a<x)) && 
    (!(y<x) && !(x<y)) && 
    (!(y<a) && !(a<y))); 
}

