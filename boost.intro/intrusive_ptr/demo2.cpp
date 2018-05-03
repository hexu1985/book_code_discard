#include <iostream>
#include "boost/intrusive_ptr.hpp"

class reference_counter {
  int ref_count_;
  public:
    reference_counter() : ref_count_(0) {}
  
    virtual ~reference_counter() {}

     friend void intrusive_ptr_add_ref(reference_counter* p) { 
       ++p->ref_count_;
     }

     friend void intrusive_ptr_release(reference_counter* p) {
       if (--p->ref_count_==0)
         delete p;
     }

  protected:
    reference_counter& operator=(const reference_counter&) {
    // 无操作
      return *this;
    }
  private:
    // 禁止复制构造函数
    reference_counter(const reference_counter&); 
};

class some_class : public reference_counter {
public:
  some_class() {
    std::cout << "some_class::some_class()\n";
  }

  some_class(const some_class& other) {
    std::cout << "some_class(const some_class& other)\n";
  }

  ~some_class() {
    std::cout << "some_class::~some_class()\n";
  }
};

int main() {
  std::cout << "Before start of scope\n";
  {
    boost::intrusive_ptr<some_class> p1(new some_class());
    boost::intrusive_ptr<some_class> p2(p1);
  }
  std::cout << "After end of scope \n";
}

