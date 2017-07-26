#include <tr1/functional>
#include <math.h>
#include <iostream>
#include <typeinfo>

using std::tr1::result_of;
using std::ostream;
using std::cout;

class C 
{
public:
	C(int i0): i(i0) {}
	long get() const { return i; }
	int i;
	void operator ()(int ii) { i = ii; }
	typedef void result_type;
};

template <class Fty, class Arg>
void show_return(Fty fun, Arg arg)
{
	typedef typename result_of<Fty(Arg)>::type ret;

	cout << "Return type of " << typeid(Fty).name()
		<< " when called with " << typeid(Arg).name()
		<< " is " << typeid(ret).name() << '\n';
}

int main()
{
	C c(1);
	C *cp = &c;
	const C *ccp = &c;
	show_return(cosf, 1.0);
	show_return(&C::get, cp);
	show_return(&C::get, cp);
	show_return(&C::i, ccp);
	show_return(c, 3);

	return 0;
}
