#include <numeric>
#include <list>
#include <functional>
#include <iostream>

using std::list;
using std::accumulate;
using std::plus;
using std::multiplies;
using std::cout;
using std::endl;

/*
 * Êä³öÎª:
   accumulate()
	operating on values {1,2,3,4}
	result with default addition: 10
	result with multiplies<int> function object: 24 
 */
int main()
{
	int ia[] = { 1, 2, 3, 4 };
	list<int> ilist( ia, ia+4 );
	
	int ia_result = accumulate(&ia[0], &ia[4], 0);
	int ilist_res = accumulate(ilist.begin(), ilist.end(), 1, multiplies<int>() );

	cout << "accumulate()\n\t"
		<< "operating on values {1,2,3,4}\n\t"
		<< "result with default addition: "
		<< ia_result << "\n\t"
		<< "result with multiplies<int> function object: "
		<< ilist_res
		<< endl;
}

