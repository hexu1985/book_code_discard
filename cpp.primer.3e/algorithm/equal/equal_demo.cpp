#include <algorithm>
#include <list>
#include <iostream>
#include <iterator>

class equal_and_odd{
public:
	bool
	operator()( int val1, int val2 )
	{
		return ( val1 == val2 &&
			( val1 == 0 || val1 % 2 ));
	}
};

using namespace std;

int main()
{
	int ia[] = { 0,1,1,2,3,5,8,13 };
	int ia2[] = { 0,1,1,2,3,5,8,13,21,34 };
	bool res;

	// true: 都等于 ia. 的长度
	// 生成结果为: int ia[7] equal to int ia2[9]? true.
	res = equal( &ia[0], &ia[7], &ia2[0] );
	cout << "int ia[7] equal to int ia2[9]? "
		<< ( res ? "true" : "false" ) << ".\n";
	list< int > ilist( ia, ia+7 );
	
	list< int > ilist2( ia2, ia2+9 );

	// 生成结果为: list ilist equal to ilist2? true.
	res = equal( ilist.begin(), ilist.end(), ilist2.begin() );
	cout << "list ilist equal to ilist2? "
		<< ( res ? "true" : "false" ) << ".\n";

	// false: 0, 2, 8 不相等, 也不是奇数
	// 生成结果为: list ilist equal_and_odd() to ilist2? false.
	res = equal( ilist.begin(), ilist.end(),
		ilist2.begin(), equal_and_odd() );
	cout << "list ilist equal_and_odd() to ilist2? "
		<< ( res ? "true" : "false" ) << ".\n";

	return 0;
}
