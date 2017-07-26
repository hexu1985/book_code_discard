#include <algorithm>
#include <functional>
#include <vector>
#include <cassert>

using namespace std;

int main()
{
	int ia[] = {29,23,20,22,17,15,26,51,19,12,35,40};
	sort( &ia[0], &ia[12] );

	bool found_it = binary_search( &ia[0], &ia[12], 18 );
	assert( found_it == false );
	
	vector< int > vec(ia, ia + sizeof (ia) / sizeof (ia[0]));
	sort( vec.begin(), vec.end(), greater<int>() );

	found_it = binary_search( vec.begin(), vec.end(),
		26, greater<int>() );
	assert( found_it == true );

	return 0;
}

