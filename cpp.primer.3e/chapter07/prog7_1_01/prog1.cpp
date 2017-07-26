#include <iostream>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

inline int abs( int iobj )
{
	// 返回 iobj 的绝对值
	return( iobj < 0 ? -iobj : iobj );
}

inline int min( int p1, int p2 )
{
	// 返回较小值
	return( p1 < p2 ? p1 : p2 );
}

int gcd( int v1, int v2 )
{
	// 返回最大公约数
	while ( v2 )
	{
		int temp = v2;
		v2 = v1 % v2;
		v1 = temp;
	}

	return v1;
}

int main()
{
	// get values from standard input
	cout << "Enter first value: ";
	int i;
	cin >> i;
	if ( !cin ) {
		cerr << "!<< Oops: input error - Bailing out!\n";
		return -1;
	}
	
	cout << "Enter second value: ";
	int j;
	cin >> j;
	if ( !cin ) {
		cerr << "!<< Oops: input error - Bailing out!\n";
		return -2;
	}
	
	cout << "\nmin: " << min( i, j ) << endl;
	i = abs( i );
	j = abs( j );
	cout << "gcd: " << gcd( i, j ) << endl;
	
	return 0;
}
