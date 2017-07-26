#include <iostream>
#include <tr1/functional>

using std::tr1::bind;
using std::cout;

int no_args()
{
	return 0;
}

struct one_arg
{
	int operator ()(int i) const
	{
		return i;
	}

	typedef int result_type;
};

struct three_args
{
	three_args(int v): val(v) {}
	int f(int i, int j) const
	{
		return val + 2 * i + 3 * j;
	}

private:
	int val;
};

int main()
{
	cout << bind(no_args)() << '\n';
	cout << no_args() << '\n';

	one_arg a1;
	cout << bind(a1, 1)() << '\n';
	cout << a1(1) << '\n';

	three_args a3(1);
	cout << bind(&three_args::f, a3, 2, 3)() << '\n';
	cout << a3.f(2, 3) << '\n';

	return 0;
}
