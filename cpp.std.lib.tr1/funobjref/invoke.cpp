#include <tr1/functional>
#include <iostream>

using std::tr1::reference_wrapper;
using std::tr1::cref;
using std::cout;

void hello()
{
	cout << "Hello, world\n";
}

void goodbye()
{
	cout << "Goodbye, cruel world\n";
}

int main()
{
	typedef void (*const fun)();
	reference_wrapper<fun> rw(&hello);
	rw();
	rw = cref(&goodbye);
	rw();

	return 0;
}
