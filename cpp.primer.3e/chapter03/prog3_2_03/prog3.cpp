/* prog3.cpp */
/* on page 65 of C++ Primer 3e */

#include <iostream>

extern int pow(int, int);

int main()
{
	using namespace std;
	int val = 2;
	int exp = 15;
	cout << "The Powers of 2\n";
	for ( int cnt=0; cnt <= exp; ++cnt )
		cout << cnt << ": "
			 << pow(val, cnt) << endl;
	return 0;
}

