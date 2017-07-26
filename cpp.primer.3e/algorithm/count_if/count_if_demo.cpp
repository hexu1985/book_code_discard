#include <algorithm>
#include <list>
#include <iostream>
#include <iterator>

class Even {
public:
	bool operator()( int val )
	{ return val%2 ? false : true; }
};

using namespace std;

int main()
{
	int ia[] = {0,1,1,2,3,5,8,13,21,34};
	list< int > ilist( ia, ia+10 );

	/*
	* 目前编译器不支持
	*****************************************************
	typedef
	iterator_traits<InputIterator>::distance_type
	distance_type;
	distance_type ia_count, list_count;
	// 计算偶数元素: 4
	ia_count = count_if( &ia[0], &ia[10], Even() );
	list_count = count_if( ilist.begin(), ilist_end(),
	bind2nd(less<int>(),10) );
	******************************************************
	*/

	int ia_count = 0;
	ia_count = count_if( &ia[0], &ia[10], Even() );

	// 生成结果为:
	// count_if(): there are 4 elements that are even.
	cout << "count_if(): there are "
		<< ia_count << " elements that are even.\n";

	int list_count = 0;
	list_count = count_if( ilist.begin(), ilist.end(),
		bind2nd(less<int>(),10) );

	// 生成结果为:
	// count_if(): there are 7 elements that are less than 10.
	cout << "count_if(): there are "
		<< list_count
		<< " elements that are less than 10.\n";

	return 0;
}
