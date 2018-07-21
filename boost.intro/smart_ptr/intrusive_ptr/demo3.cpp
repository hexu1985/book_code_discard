#include "boost/shared_ptr.hpp"
#include "boost/intrusive_ptr.hpp"
#include <iostream>

class A;

void do_stuff(boost::shared_ptr<A> p) {
    std::cout << "do_stuff shared_ptr ...." << std::endl;
}

void do_stuff(boost::intrusive_ptr<A> p) {
    std::cout << "do_stuff intrusive_ptr ...." << std::endl;
}

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

class A : public reference_counter {
public:
  void call_do_stuff() {
    do_stuff(this);
  }
};

int main() {
  boost::intrusive_ptr<A> p(new A());
  p->call_do_stuff();
}

