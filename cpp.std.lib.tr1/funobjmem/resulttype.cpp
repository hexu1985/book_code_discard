#include <tr1/functional>
#include <iostream>

using std::tr1::mem_fn;
using std::cout;

template <class Ty>
void show_result_type(Ty)
{
	cout << typeid(Ty::result_type).name() << '\n';
}

struct S
{
	int f0() { return 0; }
	long f1(int) { return 1; }
	void f2(int, int) {}
	double f3(int, int, int) { return 2.0; }
};

int main()
{
	show_result_type(mem_fn(&S::f0));
	show_result_type(mem_fn(&S::f1));
	show_result_type(mem_fn(&S::f2));
	show_result_type(mem_fn(&S::f3));

	return 0;
}
