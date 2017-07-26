#include <algorithm>
#include <list>
#include <utility>
#include <iostream>

using namespace std;

class equal_and_odd{
public:
	bool operator()( int ival1, int ival2 )
	{
		// 两个值相等吗, 或
		// 都为 0 或都为奇数
		return ( ival1 == ival2 && ( ival1 == 0 || ival1 % 2 ));
	}
};

int main()
{
	int ia[] = { 0,1,1,2,3,5,8,13 };
	int ia2[] = { 0,1,1,2,4,6,10 };

	pair<int*,int*> pair_ia = mismatch( ia, ia+7, ia2 );

	// 输出: first mismatched pair: ia: 3 and ia2: 4
	cout << "first mismatched pair: ia: "
		<< *pair_ia.first << " and ia2: "
		<< *pair_ia.second << endl;

	list<int> ilist( ia, ia+7 );
	list<int> ilist2( ia2, ia2+7 );
	typedef list<int>::iterator iter;
	pair< iter,iter > pair_ilist =
		mismatch( ilist.begin(), ilist.end(),
			ilist2.begin(), equal_and_odd() );
	// 输出:
	// first mismatched pair either not equal or not odd:
	// ilist: 2 and ilist2: 2
	cout << "first mismatched pair either not equal "
		<< "or not odd: \n\tilist: "
		<< *pair_ilist.first << " and ilist2: "
		<< *pair_ilist.second << endl;

	return 0;
}
