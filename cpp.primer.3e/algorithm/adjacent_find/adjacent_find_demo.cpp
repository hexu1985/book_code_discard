#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>

using std::vector;
using std::cout;
using std::endl;
//using std::assert;
using std::adjacent_find;

class TwiceOver {
public:
	bool operator() ( int val1, int val2 )
	{ return val1 == val2/2 ? true : false; }
};

int main()
{
	int ia[] = { 1, 4, 4, 8 };
	vector< int > vec(ia, ia + sizeof (ia) / sizeof (ia[0]));

	int *piter;
	vector< int >::iterator iter;

	// piter 指向 ia[1]
	piter = adjacent_find( ia, ia + sizeof (ia) / sizeof (ia[0]));
	assert( *piter == ia[ 1 ] );

	// iter 指向 vec[2]
	iter = adjacent_find( vec.begin(), vec.end(), TwiceOver() );
	assert( *iter == vec[ 2 ] );

	// 到达这里表示一切顺利
	cout << "ok: adjacent-find() succeeded!\n";

	return 0;
}

