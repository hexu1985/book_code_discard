#include <tr1/functional>

using std::tr1::reference_wrapper;

class ref
{
public:
	ref(int &i): member(i) {}

private:
	int &member;
};

class refwrap
{
public:
	refwrap(int &i): member(i) {}

private:
	reference_wrapper<int> member;
};

void f()
{
	int i, j;
	ref r0(i);
	ref r1(j);
	r1 = r0;

	refwrap rw0(i);
	refwrap rw1(j);
	rw1 = rw0;
}
