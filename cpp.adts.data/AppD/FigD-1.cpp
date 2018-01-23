#include <iostream>
using namespace std;

template <typename Type1, typename Type2>
void convert(Type1 value1, Type2 & value2)
  /*-------------------------------------------------------------------------
  Function template to convert a Type1 value to a Type2 value. 
  Receive:   Type parameters Type1 and Type2
             value1 of Type 1
  Pass back: value2 of Type2
  -------------------------------------------------------------------------*/
{
  value2 = static_cast<Type2>(value1);
}

int main()
{
  char a = 'a';
  int ia;
  convert(a, ia);
  cout << a << "  " << ia << endl;
  double x = 3.14;
  int ix;
  convert(x, ix);
  cout << x << "  " << ix << endl;
}
