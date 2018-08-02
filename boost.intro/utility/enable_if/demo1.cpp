#include <iostream>

void some_func(int i) {
  std::cout << "void some_func(" << i << ")\n";
}

template <typename T> void some_func(T t) {
  typename T::type variable_of_nested_type;
  std::cout << 
    "template <typename T> void some_func(" << t << ")\n";
}

int main() {
  int i=12;
  short s=12;

  some_func(i);
  some_func(s);
}

