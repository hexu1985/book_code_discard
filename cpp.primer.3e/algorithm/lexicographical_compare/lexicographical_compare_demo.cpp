#include <algorithm>
#include <list>
#include <string>
#include <cassert>
#include <iostream>

using namespace std;

class size_compare {
public:
	bool operator()( const string &a, const string &b ) 
	{
		return a.length() <= b.length();
	}
};

int main()
{
	string arr1[] = { "Piglet", "Pooh", "Tigger" };
	string arr2[] = { "Piglet", "Pooch", "Eeyore" };

	bool res;
	// 第二个元素值为 false
	// Pooch 小于 Pooh
	// 第二个元素值也为 false
	res = lexicographical_compare( arr1, arr1+3,
		arr2, arr2+3 );
	assert( res == false );

	// 值为 true: ilist2 每个元素的
	// 长度都小于或等于
	// 对应的 ilist1 的元素
	list< string > ilist1( arr1, arr1+3 );
	list< string > ilist2( arr2, arr2+3 );
	res = lexicographical_compare(
		ilist1.begin(), ilist1.end(),
		ilist2.begin(), ilist2.end(), size_compare() );
	assert( res == true );
	cout << "ok: lexicographical_compare succeeded!\n";

	return 0;
}
