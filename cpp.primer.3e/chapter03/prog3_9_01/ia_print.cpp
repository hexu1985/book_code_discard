/* ia_print.cpp */
/* on page 98 of C++ Primer 3e */

#include <iostream>

void ia_print( int *pbegin, int *pend )
{
	using std::cout;
	while ( pbegin != pend ) {
		cout << *pbegin << ' ';
		++pbegin;
	}
}

int main()
{
	int ia[9] = { 0, 1, 1, 2, 3, 5, 8, 13, 21 };
	ia_print( ia, ia + 9 );
}
