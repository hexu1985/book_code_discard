#include "ArrayT.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

namespace hexu { // begin namespace of hexu
	
template <class Type>
Type min( Type a, Type b ) {
	return a < b ? a : b;
}

template <class elemType>
void swap( Array<elemType> &array, int i, int j )
{
	elemType tmp = array[ i ];
	array[ i ] = array[ j ];
	array[ j ] = tmp;
}

} // end namespace of hexu

template <class elemType>
void sort( Array<elemType> &array, int low, int high ) {
	if ( low < high ) {
		int lo = low;
		int hi = high + 1;
		elemType elem = array[lo];
		
		for (;;) {
			while ( hexu::min( array[++lo], elem ) != elem && lo < high ) ;
			while ( hexu::min( array[--hi], elem ) == elem && hi > low ) ;
			if (lo < hi)
				hexu::swap( array, lo, hi );
			else break;
		}
		
		hexu::swap( array, low, hi );
		sort( array, low, hi-1 );
		sort( array, hi+1, high );
	}
}

template <class elemType>
void display( Array<elemType> &array )
{ // display format: < 0 1 2 3 4 5 >
	cout << "< ";
	for ( int ix = 0; ix < array.size(); ++ix )
	cout << array[ix] << " ";
	cout << ">\n";
}
	
double da[10] = {26.7, 5.7, 37.7, 1.7, 61.7, 11.7, 59.7, 15.7, 48.7, 19.7 };
int ia[16] = {503, 87, 512, 61, 908, 170, 897, 275, 653, 426, 154, 509, 612, 677, 765, 703 };
string sa[11] = {"a", "heavy", "snow", "was", "falling", "when", "they", "left", "the", "police", "station" };

int main() {
	// 调用构造函数初始化 arrd
	Array<double> arrd( da, sizeof(da)/sizeof(da[0]) );
	// 调用构造函数初始化 arri
	Array<int> arri( ia, sizeof(ia)/sizeof(ia[0]) );
	// 调用构造函数初始化 arrs
	Array<string> arrs( sa, sizeof(sa)/sizeof(sa[0]) );
	
	cout << "sort array of doubles (size == "
		<< arrd.size() << ")" << endl;
	sort( arrd, 0, arrd.size()-1 );
	display(arrd);
	cout << "\nsort array of ints (size == "
		<< arri.size() << ")" << endl;
	sort( arri, 0, arri.size()-1 );
	display(arri);
	cout << "\nsort array of strings (size == "
		<< arrs.size() << ")" << endl;
	sort( arrs, 0, arrs.size()-1 );
	display(arrs);
	
	return 0;
}
