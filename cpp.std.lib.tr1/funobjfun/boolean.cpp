#include <tr1/functional>
#include <iostream>
#include <math.h>

using std::tr1::function;
using std::cout;

void report(const char *title, bool val)
{
	cout << title << ": object is ";
	if (val)
		cout << "not ";
	cout << "empty\n";
}

int main()
{
	function<float(float)> fn;
	report("after construction", fn);
	fn = cosf;
	report("after assigning target object", fn);
	fn = 0;
	report("after assigning null pointer", fn);

	return 0;
}
