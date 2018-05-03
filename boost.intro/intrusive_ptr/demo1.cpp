#include <iostream>
#include "boost/intrusive_ptr.hpp"

template <typename T> void intrusive_ptr_add_ref(T* t) {
  t->add_ref();
}

template <typename T> void intrusive_ptr_release(T* t) {
  if (t->release()<=0)
    delete t;
}

class reference_counter {
  int ref_count_;
  public:
    reference_counter() : ref_count_(0) {}
  
    virtual ~reference_counter() {}

    void add_ref() { 
      ++ref_count_;
    }

    int release() {
      return --ref_count_;
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

