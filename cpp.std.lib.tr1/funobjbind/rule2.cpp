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
	one_arg a2;
	three_args a3(2);

	cout << bind(a1, bind(a2, a))() << '\n';
	cout << a1(a2(a)) << '\n';

	cout << bind(a1, bind(a2, _1))(b) << '\n';
	cout << a1(a2(b)) << '\n';

	cout << bind(a1, bind(a2, _1))(a, b) << '\n';
	cout << a1(a2(a)) << '\n';
	cout << bind(&three_args::f, a3,
			bind(a1, _1), bind(a2, _1))(a, b) << '\n';
	cout << a3.f(a1(a), a2(a)) << '\n';

	return 0;
}
