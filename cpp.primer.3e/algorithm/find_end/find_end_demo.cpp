#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>

using namespace std;

int main()
{
	int array[ 17 ] = { 7,3,3,7,6,5,8,7,2,1,3,7,6,3,8,4,3 };
	int subarray[ 3 ] = { 3, 7, 6 };
	int *found_it;

	// 在数组中查找最后一次出现的 3,7,6 序列
	// 返回首元素的地址...
	found_it = find_end( &array[0], &array[17],
						 &subarray[0], &subarray[3] );
	assert( found_it == &array[10] );

	vector< int > ivec( array, array+17 );
	vector< int > subvec( subarray, subarray+3 );

	vector< int >::iterator found_it2;
	found_it2 = find_end( ivec.begin(), ivec.end(),
							subvec.begin(), subvec.end(),
							equal_to<int>() );
	assert( found_it2 == ivec.begin()+10 );

	cout << "ok: find_end correctly returned beginning of "
		<< "last matching sequence: 3,7,6!\n";

	return 0;
}

