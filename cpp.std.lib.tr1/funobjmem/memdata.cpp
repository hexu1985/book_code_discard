#include <tr1/functional>
#include <iostream>
#include <typeinfo>

using std::tr1::mem_fn;
using std::cout;

template <class Ty>
void show_type(Ty)
{
	cout << typeid(Ty).name() << '\n';
}

struct S
{
	S(): i(0), j(1) {}
	int i;
	const double j;
};

int main()
{
	S s;
	const S cs;
	show_type(mem_fn(&S::i)(s));
	show_type(mem_fn(&S::i)(cs));
	show_type(mem_fn(&S::j)(s));
	show_type(mem_fn(&S::j)(cs));

	return 0;
}
