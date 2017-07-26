#include <tr1/functional>
#include <iostream>
#include <typeinfo>
#include <math.h>

using std::tr1::function;
using std::cout;
using std::type_info;

typedef function<float(float)> Fty;
typedef float (*fptr)(float);

struct S
{
	float operator ()(float) { return 1.0f; }
	typedef float result_type;
};

void show_pointer(const char *title, Fty &fty)
{
	cout << title << ": ";
	if (fty.target<fptr>())
		cout << " target has type pointer to function\n";
	else if (fty.target<S>())
		cout << " target has type S\n";
	else
		cout << " target is empty or has unknown type\n";
}

int main()
{
	function<float(float)> fn;
	show_pointer("empty", fn);
	fn = cosf;
	show_pointer("cosf", fn);
	fn = S();
	show_pointer("S", fn);

	return 0;
}

