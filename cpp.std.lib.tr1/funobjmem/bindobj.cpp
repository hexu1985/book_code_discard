#include <tr1/functional>
#include <tr1/memory>
#include <iostream>

using std::tr1::mem_fn;
using std::tr1::shared_ptr;
using std::cout;

class C
{
public:
	C(int i0 = 0): i(i0) {}

	void show() const
	{
		cout << i << '\n';
	}

private:
	int i;
};

template <class Fty, class Ty>
void apply(Fty fn, Ty obj)
{
	fn(obj);
}

int main()
{
	C c0(0);
	C *cp = new C(1);
	shared_ptr<C> sp(new C(2));
	void (C::*mptr)() const = &C::show;

	apply(mem_fn(mptr), c0);
	apply(mem_fn(mptr), cp);
	apply(mem_fn(mptr), sp);

	delete cp;

	return 0;
}
