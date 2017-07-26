#include <tr1/functional>
#include <iostream>

using std::tr1::bind;
using std::tr1::ref;
using std::cout;

void modify(int &arg)
{
	++arg;
}

int main()
{
	int i = 0;
	cout << i << '\n';

	bind(modify, i)();
	cout << i << '\n';

	bind(modify, ref(i))();
	cout << i << '\n';

	return 0;
}
