#include <tr1/functional>
#include <iostream>

using std::tr1::function;
using std::cout;

int func()
{
	return 0;
}

void report(const char *title, bool val)
{
	cout << title << ": object is ";
	if (val)
		cout << "not ";
	cout << "empty\n";
}

int main()
{
	function<int()> f0;
	function<int()> f1(func);
	report("f0 before swap", f0);
	report("f1 before swap", f1);
	f0.swap(f1);
	report("f0 after swap", f0);
	report("f1 after swap", f1);

	return 0;
}
