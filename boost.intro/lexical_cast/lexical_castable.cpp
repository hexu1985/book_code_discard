#include <iostream>
#include <string>
#include "boost/lexical_cast.hpp"

class lexical_castable {
public:
    lexical_castable() {};
    lexical_castable(const std::string s) : s_(s) {};
 
    friend std::ostream &operator<<
        (std::ostream& o, const lexical_castable& le);
    friend std::istream &operator>>
        (std::istream& i, lexical_castable& le);

private:
    virtual void print_(std::ostream& o) const {
        o << s_; 
    }

    virtual void read_(std::istream& i) {
        i >> s_;
    }

    std::string s_;
};

std::ostream &operator<<(std::ostream& o,
        const lexical_castable& le) {
    le.print_(o);
    return o;
}

std::istream &operator>>(std::istream& i, lexical_castable& le) {
    le.read_(i);
    return i;
}

int main(int argc, char* argv[]) {
    lexical_castable le;
    std::cin >> le;

    try {
        int i = boost::lexical_cast<int>(le);
    }
    catch(boost::bad_lexical_cast&) {
        std::cout << "You were supposed to enter a number!\n";
    }
}
