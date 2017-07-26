#include <tr1/tuple>
#include <iostream>

using std::tr1::make_tuple;
using std::tr1::tie;
using std::tr1::ignore;

int i = 1;
int j = 2;
int k = 3;

void show()
{
	std::cout << i << ' ' << j << ' ' << k << '\n';
}

int main()
{
	show();
	tie(i, ignore, k) = make_tuple(5, 6 ,7);
	show();

	return 0;
}
