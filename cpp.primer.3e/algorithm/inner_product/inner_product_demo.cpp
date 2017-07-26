#include <numeric>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	int ia[] = { 2, 3, 5, 8 };
	int ia2[] = { 1, 2, 3, 4 };

	// 两个数组的元素两两相乘,
	// 并将结果添加到初始值: 0
	int res = inner_product( &ia[0], &ia[4], &ia2[0], 0);
	// 结果: inner product of arrays: 55
	cout << "inner product of arrays: "
		<< res << endl;

	vector<int> vec( ia, ia+4 );
	vector<int> vec2( ia2, ia2+4 );
	// 两个向量中的元素相加
	// 并从初始值中减去和: 0
	res = inner_product( vec.begin(), vec.end(),
			vec2.begin(), 0,
			minus<int>(), plus<int>() );
	// 结果: inner product of vectors: -28
	cout << "inner product of vectors: "
		<< res << endl;

	return 0;
}
