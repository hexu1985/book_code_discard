#include <tr1/functional>
#include <iostream>

using std::tr1::reference_wrapper;
using std::cout;

struct base
{
	virtual void show() const
	{
		cout << "base\n";
	}
};

struct derived0: base
{
	void show() const
	{
		cout << "derived0\n";
	}
};

struct derived1: base
{
	void show() const
	{
		cout << "derived1\n";
	}
};

int main()
{
	derived0 Crowley;
	derived1 Layden;
	reference_wrapper<base> rw0(Crowley);
	rw0.get().show();
	reference_wrapper<base> rw1(Layden);
	rw1.get().show();

	return 0;
}
