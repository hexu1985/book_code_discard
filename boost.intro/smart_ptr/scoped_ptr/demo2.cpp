#include "boost/scoped_ptr.hpp"
#include <string>
#include <memory>

void scoped_vs_auto() {
    using boost::scoped_ptr;
    using std::auto_ptr;
    scoped_ptr<std::string> p_scoped(new std::string("Hello"));
    auto_ptr<std::string> p_auto(new std::string("Hello"));
    p_scoped->size();
    p_auto->size();
    //scoped_ptr<std::string> p_another_scoped=p_scoped;  // will compile error
    auto_ptr<std::string> p_another_auto=p_auto;
    p_another_auto->size();
    (*p_auto).size();
}

int main()
{
    scoped_vs_auto();
}
