/* prog2.cpp */
/* on page 65 of C++ Primer 3e */

#include <iostream>

int main()
{
	using namespace std;
	
	// int 类型的对象
	int value = 2;
	int pow = 10;
	
	cout << value << " raised to the power of "
		 << pow << ": \t";
	int res = 1; // 保存结果
	
	// 循环控制语句: 反复计算res
	// 直至cnt 大于pow
	for ( int cnt=1; cnt <= pow; ++cnt)
		res = res * value;
	cout << res << endl;
}
