#include <tr1/functional>
#include <iostream>

using std::tr1::mem_fn;
using std::cout;

class C
{
public:
	C(int i0 = 0): i(i0) {}

	void show() const
	{
		cout << "in show: " << i << '\n';
	}

	void one_arg(int j) const
	{
		cout << "in one_arg: " << i
			<< ", " << j << '\n';
	}

	void two_args(int j, int k) const
	{
		cout << "in two_arg: " << i
			<< ", " << j << ", " << k << '\n';
	}

private:
	int i;
};

int main()
{
	C c(1);
	int two = 2;
	int three = 3;
	mem_fn(&C::show)(c);
	mem_fn(&C::one_arg)(c, two);
	mem_fn(&C::two_args)(c, two, three);

	return 0;
}
