#include <iostream>

using std::cout;
using std::endl;

extern int traceGcd(int, int);

int main() {
	int rslt = traceGcd( 15, 123 );
	cout << "gcd of (15,123): " << rslt << endl;
	return 0;
}

int traceGcd( int v1, int v2 )
{
	static int depth = 1;
	cout << "depth #" << depth++ << endl;
	if ( v2 == 0 ) {
		depth = 1;
		return v1;
	}
	return traceGcd( v2, v1%v2 );
}
