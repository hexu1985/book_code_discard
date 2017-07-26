/* prog3.cpp */
/* on page 131 of C++ Primer 3e */

#include <iostream>
#include <complex>

using std::complex;
using std::cout;
using std::endl;

// 递增操作符的定义在这里
template <typename T>
complex<T> &operator ++(complex<T> &cval)
{
	cval += 1;
	return cval;
}

int main()
{
	complex< double > cval( 4.0, 1.0 );
	cout << cval << endl;
	++cval;
	cout << cval << endl;
}
