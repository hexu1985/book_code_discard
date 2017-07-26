/* t_print.cpp */
/* on page 99 of C++ Primer 3e */

#include <iostream>

template <typename elemType>
void print( elemType *pbegin, elemType *pend )
{
	using std::cout;
	while ( pbegin != pend ) {
		cout << *pbegin << ' ';
		++pbegin;
	}
}

int main()
{
	using std::string;
	int ia[9] = { 0, 1, 1, 2, 3, 5, 8, 13, 21 };
	double da[4] = { 3.14, 6.28, 12.56, 25.12 };
	string sa[3] = { "piglet", "eeyore", "pooh" };
	print( ia, ia+9 );
	print( da, da+4 );
	print( sa, sa+3 );
}
