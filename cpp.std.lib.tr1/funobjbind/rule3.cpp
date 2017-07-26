#include <iostream>
#include <tr1/functional>

using std::tr1::bind;
using namespace std::tr1::placeholders;
using std::cout;

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
	int a = 10;
	int b = 11;
	int c = 12;

	one_arg a1;
	cout << bind(a1, _1)(a, b, c) << '\n';
	cout << a1(a) << '\n';
	cout << bind(a1, _2)(a, b, c) << '\n';
	cout << a1(b) << '\n';
	cout << bind(a1, _3)(a, b, c) << '\n';
	cout << a1(c) << '\n';
	cout << bind(a1, 10)(a, b, c) << '\n';
	cout << a1(10) << '\n';

	three_args a3(1);
	cout << bind(&three_args::f, a3, _1, _2)(a, b, c) << '\n';
	cout << a3.f(a, b) << '\n';
	cout << bind(&three_args::f, a3, _2, _3)(a, b, c) << '\n';
	cout << a3.f(b, c) << '\n';
	cout << bind(&three_args::f, a3, _3, _2)(a, b, c) << '\n';
	cout << a3.f(c, b) << '\n';
	cout << bind(&three_args::f, a3, 1, _2)(a, b, c) << '\n';
	cout << a3.f(1, b) << '\n';

	return 0;
}
