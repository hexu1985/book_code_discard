#include <iostream>
using namespace std;

template <typename Type1, typename Type2>
Type2 convert(Type1 value1)
/*-------------------------------------------------------------------------
  Function template to convert a Type1 value to a Type2 value. 
  Receive:  Type parameters Type1 and Type2
            value1 of Type 1
  Return:   value1 converted to Type2
-------------------------------------------------------------------------*/
{
  return static_cast<Type2>(value1);
}

int main()
{
  char a = 'a';
  int ia = convert<char, int>(a);
  cout << a << "  " << ia << endl;
  double x = 3.14;
  int ix = convert<double, int>(x);
  cout << x << "  " << ix << endl;
}
