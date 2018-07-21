#include "boost/scoped_ptr.hpp"
#include <string>
#include <iostream>
int main() {
    {
        boost::scoped_ptr<std::string>
            p(new std::string("Use scoped_ptr often."));

        // 打印字符串的值
        if (p)
            std::cout << *p << '\n';

        // 获取字符串的大小
        size_t i=p->size();
        // 给字符串赋新值
        *p="Acts just like a pointer";

    } // 这里p 被销毁，并删除std::string
}
