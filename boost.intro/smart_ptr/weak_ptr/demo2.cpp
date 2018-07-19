#include <iostream>
#include <string>

#include <vector>
#include <algorithm>
#include <functional>
#include "boost/shared_ptr.hpp"
#include "boost/weak_ptr.hpp"

template <typename Func, typename T> 
  struct weak_ptr_unary_t : 
    public std::unary_function<boost::weak_ptr<T>,bool> {
  T t_;
  Func func_;

  weak_ptr_unary_t(const Func& func,const T& t) 
    : t_(t),func_(func) {}

  bool operator()(boost::weak_ptr<T> arg) const {
    boost::shared_ptr<T> sp=arg.lock();
    if (!sp) {
      return false;
    }
    return func_(*sp,t_);
  }
};

template <typename Func, typename T> weak_ptr_unary_t<Func,T> 
  weak_ptr_unary(const Func& func, const T& value) {
    return weak_ptr_unary_t<Func,T>(func,value);
}


int main() {
  using std::string;
  using std::vector;
  using boost::shared_ptr;
  using boost::weak_ptr;

  vector<weak_ptr<string> > vec;

  shared_ptr<string> sp1(
    new string("An example"));
  shared_ptr<string> sp2(
    new string("of using"));
  shared_ptr<string> sp3(
    new string("smart pointers and predicates"));
  vec.push_back(weak_ptr<string>(sp1));
  vec.push_back(weak_ptr<string>(sp2));
  vec.push_back(weak_ptr<string>(sp3));

  vector<weak_ptr<string> >::iterator
    it=std::find_if(vec.begin(),vec.end(),
     weak_ptr_unary(std::equal_to<string>(),string("of using")));

  if (it!=vec.end()) {
    shared_ptr<string> sp(*++it);
    std::cout << *sp << '\n';
  }
}

