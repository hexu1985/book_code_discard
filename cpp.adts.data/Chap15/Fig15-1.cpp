#include <iostream>
#include <string>
#include <map>
using namespace std;

class Student
{
public:
  //--- Constructor
  Student (int id = 0, double gpa = 0);
  //--- Output operator
  friend ostream & operator<<(ostream & out, const Student & s);
  //--- Input operator
  friend istream & operator>>(istream & in, Student & s);
  //--- Less-than operator
  friend bool operator<(const Student & a, const Student & b);
private:
  //--- Data members
  int myId;
  double myGPA;
};  // end of class Student

//--- Definition of constructor
inline Student::Student(int id, double gpa)
  : myId(id), myGPA(gpa)
{ }

//--- Definition of input operator
inline istream & operator>>(istream & in, Student & s)
{
  in >> s.myId >> s.myGPA;
}

//--- Definition of output operator
inline ostream & operator<<(ostream & out, const Student & s)
{ out << "id = " << s.myId << "  GPA = " << s.myGPA;
 return out;
}

//--- Definition of less-than operator
inline bool operator<(const Student & a, const Student & b)
{ return a.myId < b.myId; }

//==================================================================

int main()
{
  typedef map<string, Student, less<string> > map1;
  typedef map<Student, string, less<Student> > map2;

  map1 a1;   // associative array of Student, index type is string
  map2 a2;   // associative array of string, index type is Student

  Student s;
  s = Student(12345, 3.3);  a1["Fred"] = s;   a2[s] = "Fred";
  s = Student(32322, 3.9);  a1["Al"] = s;     a2[s] = "Al";
  s = Student(13131, 2.5);  a1["Joan"] = s;   a2[s] = "Joan";
  s = Student(22121, 4.0);  a1["Barb"] = s;   a2[s] = "Barb";
  s = Student(28888, 2.9);  a1["George"] = s; a2[s] = "George";
  s = Student(19981, 3.0);  a1["Dot"] = s;    a2[s] = "Dot";
  s = Student(20012, 2.9);  a1["Sue"] = s;    a2[s] = "Sue";
  string name;
  cout << "Enter a name: ";
  cin >> name;
  map1::iterator it1 = a1.find(name);
  cout << name << " has ";
  if (it1 == a1.end())
    cout << "no info";
  else
    cout << a1[name];
  cout << endl;

  Student aStudent;
  cout << "Enter a Student's id and GPA: ";
  cin >> aStudent;
  map2::iterator it2 = a2.find(aStudent);
  cout << "Student " << aStudent << " is ";

  if (it2 == a2.end())
    cout << "no info";
  else
    cout << a2[aStudent];
  cout << endl;
}