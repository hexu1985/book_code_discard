/* The following code example is taken from the book
 * "C++ Templates - The Complete Guide"
 * by David Vandevoorde and Nicolai M. Josuttis, Addison-Wesley, 2002
 *
 * (C) Copyright David Vandevoorde and Nicolai M. Josuttis 2002.
 * Permission to copy, use, modify, sell and distribute this software
 * is granted provided this copyright notice appears in all copies.
 * This software is provided "as is" without express or implied
 * warranty, and with no claim as to its suitability for any purpose.
 */
#include <iostream>
#include "hastypet.hpp"

class MyClass1 {
public:
    typedef int type;
};

struct MyClass2 {
};

struct MyClass3 {
private:
    typedef int type;
};

// check by passing type as template argument
template <typename T>
void check()
{
    if (HasTypeT<T>::Yes) {
        std::cout << " HasTypeT " << std::endl;
    }
    else {
        std::cout << " !HasTypeT " << std::endl;
    }
}

// check by passing type as function call argument
template <typename T>
void checkT (T)
{
    check<T>();
}

int main()
{
    std::cout << "int:     ";
    check<int>();

    std::cout << "int:";
    checkT(int());

    std::cout << "MyClass1: ";
    check<MyClass1>();

    std::cout << "MyClass1:";
    MyClass1 s;
    checkT(s);

    std::cout << "MyClass2: ";
    check<MyClass2>();

    std::cout << "MyClass3: ";
    check<MyClass3>();
}
