/* prog4.cpp */
/* on page 132 of C++ Primer 3e */

#include <iostream>

using std::cout;
using std::endl;

int main()
{
	int i = 10, j = 20, k = 30;
	cout << "The larger value of "
		 << i << " and " << j << " is "
		 << ( i > j ? i : j ) << endl;
	cout << "The value of " << i << " is"
		 << ( i % 2 ? " odd." : " even." )
		 << endl;

	/* 条件操作符可以被嵌套
	 * 但是深度的嵌套比较难读
	 * 在本例中
	 * max 被设置为3 个变量中的最大值
	*/
	int max = ( (i > j) ? (( i > k) ? i : k) : ( j > k ) ? j : k);
	cout << "The larger value of "
		 << i << ", " << j << " and " << k
		 << " is " << max << endl;
}
