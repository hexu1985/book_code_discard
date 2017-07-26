#include <numeric>
#include <list>
#include <functional>
#include <iterator>
#include <iostream>

using std::list;
using std::adjacent_difference;
using std::copy;
using std::multiplies;
using std::ostream_iterator;
using std::cout;
using std::endl;

int main()
{
	int ia[] = { 1, 1, 2, 3, 5, 8, 3, 9, -1};

	list<int> ilist(ia, ia + sizeof (ia) / sizeof (ia[0]));
	list<int> ilist_result(ilist.size());
	adjacent_difference(ilist.begin(), ilist.end(), ilist_result.begin());

	// 输出为:
	// 1 0 1 1 2 3 -5 6 -10

	copy(ilist_result.begin(), ilist_result.end(), 
		ostream_iterator<int>(cout," "));
	cout << endl;

	adjacent_difference( ilist.begin(), ilist.end(),
		ilist_result.begin(), multiplies<int>() );

	// 输出为:
	// 1 1 2 6 15 40 24 27 -9
	copy( ilist_result.begin(), ilist_result.end(),
		ostream_iterator<int>(cout," "));
	cout << endl;
}

