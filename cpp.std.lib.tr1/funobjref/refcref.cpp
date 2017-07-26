#include <tr1/functional>
#include <iostream>

using std::tr1::reference_wrapper;
using std::tr1::ref;
using std::tr1::cref;
using std::cout;

void show(int &i)
{
	cout << "int &: " << i << '\n';
}

void show(const int &i)
{
	cout << "const int &: " << i << '\n';
}

int main()
{
	int Miller = 3;
	show(ref(Miller));
	reference_wrapper<int> rw0(Miller);
	show(ref(rw0));
	show(cref(Miller));
	reference_wrapper<const int> rw1(Miller);
	show(cref(rw1));

	return 0;
}
