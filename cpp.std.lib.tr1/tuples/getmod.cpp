#include <tr1/tuple>
#include <iostream>

using std::tr1::tuple;
using std::tr1::get;
using std::cout;

void show(int i, int j, const tuple<int, int &, int> t)
{
	cout << i << ' ' << j << ": "
		<< get<0>(t) << ' '
		<< get<1>(t) << ' '
		<< get<2>(t) << '\n';
}

int main()
{
	int i = 1, j = 2;
	tuple<int, int &, int> t0(i, j, 3);
	show(i, j, t0);
	get<0>(t0) = 4;
	get<1>(t0) = 5.1;

	get<2>(t0) = '\6';
	show(i, j, t0);

	return 0;
}
