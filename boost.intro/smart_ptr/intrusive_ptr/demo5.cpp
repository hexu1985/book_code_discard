#include <iostream>
#include "boost/intrusive_ptr.hpp"

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

void intrusive_ptr_add_ref(reference_counter* t) {
  t->add_ref();
}

void intrusive_ptr_release(reference_counter* t) {
  if (t->release()<=0)
    delete t;
}

class good_class : public reference_counter {
};

namespace my_namespace {
  class another_class : public reference_counter {
  public:
    void call_before_destruction() const {
      std::cout << 
        "Yes, I'm ready before destruction\n";
    }
  };

  class derived_class : public another_class {};

   template <typename T> void intrusive_ptr_add_ref(T* t) {
     t->add_ref();
   }

  template <typename T> void intrusive_ptr_release(T* t) {
    if (t->release()<=0) {
      t->call_before_destruction();
      delete t;
    }
  }
}

int main() {
  boost::intrusive_ptr<my_namespace::another_class> 
    p1(new my_namespace::another_class());
  boost::intrusive_ptr<good_class> 
    p2(new good_class());
  boost::intrusive_ptr<my_namespace::derived_class> 
    p3(new my_namespace::derived_class());
}

