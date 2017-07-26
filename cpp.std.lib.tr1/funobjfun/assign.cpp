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
	function<int()> f0(func), f1;
	report("after construction from func", f0);
	f0 = f1;
	report("assigned empty function object", f0);
	f0 = func;
	report("assigned func", f0);
	f0 = 0;
	report("assigned 0", f0);
	f0 = obj;
	report("assigned obj", f0);

	return 0;
}
