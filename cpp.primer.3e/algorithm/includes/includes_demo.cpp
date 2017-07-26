#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	int ia1[] = { 13, 1, 21, 2, 0, 34, 5, 1, 8, 3, 21, 34 };
	int ia2[] = { 21, 2, 8, 3, 5, 1 };

	// includes 必须传入已排序的容器
	sort( ia1, ia1+12 ); sort( ia2, ia2+6 );
	// 结果: every element of ia2 contained in ia1? true
	bool res = includes( ia1, ia1+12, ia2, ia2+6 );
	cout << "every element of ia2 contained in ia1? "
		<< (res ? "true" : "false") << endl;

	vector< int > ivect1( ia1, ia1+12 );
	vector< int > ivect2( ia2, ia2+6 );
	// 按降序排序
	sort( ivect1.begin(), ivect1.end(), greater<int>() );
	sort( ivect2.begin(), ivect2.end(), greater<int>() );
	res = includes( ivect1.begin(), ivect1.end(),
				ivect2.begin(), ivect2.end(),
				greater<int>() );
	// 结果:
	// every element of ivect2 contained in ivect1? true
	cout << "every element of ivect2 contained in ivect1? "
		<< (res ? "true" : "false") << endl;

	return 0;
}
