#include <algorithm>
#include <vector>
#include <iterator>
#include <iostream>

/* 生成:
	0 1 1 3 5 8 13
	将数组序列左移 1 位
	1 1 3 5 8 13 13
	将 vector 序列左移 2 位
	1 3 5 8 13 8 13
 */

using namespace std;

int main()
{
	int ia[] = { 0, 1, 1, 3, 5, 8, 13 };
	vector< int > vec( ia, ia+7 );
	ostream_iterator< int > ofile( cout, " " );

	cout << "original element sequence:\n";
	copy( vec.begin(), vec.end(), ofile ); cout << '\n';

	// 左移 1 位
	copy( ia+1, ia+7, ia );
	cout << "shifting array sequence left by 1:\n";
	copy( ia, ia+7, ofile ); cout << '\n';

	// 左移 2 位
	copy( vec.begin()+2, vec.end(), vec.begin() );
	cout << "shifting vector sequence left by 2:\n";
	copy( vec.begin(), vec.end(), ofile ); cout << '\n';

	return 0;
}
