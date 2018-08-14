#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include "boost/operators.hpp"
#include "boost/bind.hpp"

class animal : boost::less_than_comparable<animal, 
boost::equality_comparable<animal> > {
  std::string name_;
  int age_;
public:
  animal(const std::string& name,int age)
    :name_(name),age_(age) {}

  void print() const {
    std::cout << name_ << " with the age " << age_ << '\n';
  }   

  friend bool operator<(const animal& lhs, const animal& rhs) {
    return lhs.name_<rhs.name_;
  }

  friend bool operator==(const animal& lhs, const animal& rhs) {
    return lhs.name_==rhs.name_ && lhs.age_==rhs.age_;
  }

};

int main() {
  animal a1("Monkey", 3);
  animal a2("Bear", 8);
  animal a3("Turtle", 56);
  animal a4("Monkey", 5);

  std::set<animal> s;
  s.insert(a1);
  s.insert(a2);
  s.insert(a3);
  s.insert(a4);

  std::cout << "Number of animals: " << s.size() << '\n';
  std::for_each(s.begin(),s.end(),boost::bind(&animal::print,_1));
  std::cout << '\n';

  std::set<animal>::iterator it(s.find(animal("Monkey",200)));
  if (it!=s.end()) {
    std::cout << "Amazingly, there's a 200 year old monkey "
      "in this set!\n";
    it->print();
  }

  it=std::find(s.begin(),s.end(),animal("Monkey",200));
  if (it==s.end()) {
    std::cout << "Of course there's no 200 year old monkey "
      "in this set!\n";
  }
}

