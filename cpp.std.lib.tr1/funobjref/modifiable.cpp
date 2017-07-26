#include <tr1/functional>
#include <iostream>

using std::tr1::reference_wrapper;
using std::cout;

struct S
{
	void operator ()(int &i)
	{
		++i;
	}
	typedef void result_type;
};

int main()
{
	int i = 0;
	S s;
	reference_wrapper<S> rw(s);
	cout << "Before call: " << i << '\n';
	rw(i);
	cout << "After call: " << i << '\n';

	return 0;
}
