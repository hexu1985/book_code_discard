#include <algorithm>
#include <vector>
#include <iostream>
#include <functional>

using namespace std;

template <class Type>
void print_elements( Type elem );

template <class Type>
void print_elements( Type elem ) { cout << elem << " "; }

void print_int(int elem) { cout << elem << " "; }

int main()
{
	vector< int > ivec;
	for ( int ix = 0; ix < 10; ix++ )
		ivec.push_back( ix );

	void (*pfi)( int ) = print_elements;
	for_each( ivec.begin(), ivec.end(), pfi );
	
	for_each( ivec.begin(), ivec.end(), print_elements<int> );

	return 0;
}
