#include <tr1/functional>
#include <iostream>

using std::tr1::function;
using std::cout;

int func()
{
	return 0;
}

struct S
{
	int operator ()() const
	{
		return 1;
	}
	typedef int result_type;
} obj;

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
	report("after default construction", f0);
	function<int()> f1(0);
	report("after construction from 0", f1);
	function<int()> f2(f1);
	report("after construction from f1", f2);
	function<int()> f3(func);
	report("after construction from func", f3);
	function<int()> f4(obj);
	report("after construction from obj", f4);

	return 0;
}
