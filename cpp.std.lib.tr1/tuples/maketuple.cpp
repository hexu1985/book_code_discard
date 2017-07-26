#include <tr1/tuple>
#include <typeinfo>
#include <iostream>

using std::tr1::tuple;
using std::tr1::make_tuple;

template <class T> void show_type(T)
{
	std::cout << typeid(T).name() << "\n\n";
}

int main()
{
	int i = 3;
	int &j = i;
	show_type(make_tuple());
	show_type(make_tuple(1, 3.14));
	show_type(make_tuple(i, j));

	return 0;
}
