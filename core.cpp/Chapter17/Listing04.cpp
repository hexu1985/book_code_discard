// Listing 17.4	Example of a template class with two type parameters.

#include <iostream.h> 
#include <stdlib.h>

class Point {
	int x, y;
friend ostream& operator << (ostream& out, const Point& p);
public:
	Point() { }                // default constructor: empty
	Point(const Point &p)      // copy constructor: for return
	{ x = p.x;  y = p.y; }
	Point(int a, int b)        // general constructor: set Point
	{ x = a;  y = b; }
	void set(int a, int b)     // set Point coordinates
	{ x = a;  y = b; }
       bool operator == (const Point& p) const
       { return x == p.x && y == p.y; }
} ;

ostream& operator << (ostream& out, const Point& p)
{ out << "(" << p.x << "," << p.y << ")"; 
  return out; }

template <class Key, class Data>
class DictEntry {
   Key  key;
   Data info;
public:
  DictEntry () { }                // empty default constructor
  DictEntry(const Key& k, const Data& d)
	  : key(k),info(d) {}      // initialize data fields
  Key getKey() const
  { return key; }                 // return key value
  Data getInfo() const
  { return info; }                // return information value
  void setKey(const Key& k) 
  { key = k; }                    // set key value
  void setInfo(const Data& d)
  { info = d; }                   // set information value
 } ;

int main()
{ 
  DictEntry<Point,char*> data[5];
  data[0].setKey(Point(1,2)); data[0].setInfo("Initial stage");
  data[1].setKey(Point(3,4)); data[1].setInfo("Analysis");
  data[2].setKey(Point(5,6)); data[2].setInfo("Design");
  data[3].setKey(Point(7,8)); data[3].setInfo("Implementation");
  data[4].setKey(Point(9,0)); data[4].setInfo("Testing");
  int n = sizeof(data)/sizeof(DictEntry<Point,char*>); // risky
  cout << "Associated Data:\n";
  for (int j = 0;  j < n;  j++)     
  { cout << data[j].getKey() << " " 
         << data[j].getInfo() << endl; }       // print input data
  cout << endl;
  return 0;
  }
