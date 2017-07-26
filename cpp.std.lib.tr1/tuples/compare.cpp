#include <iostream>
#include <iomanip>
#include <tr1/tuple>

using std::tr1::tuple;
using std::cout;
using std::boolalpha;

class C
{
public:
	C(int i): val(i) {}
	int value() const { return val; }

private:
	int val;
};

bool operator ==(const C &left, const C &right)
{
	bool res = left.value() == right.value();
	cout << "    " << left.value()
		<< " == " << right.value();
	cout << " is " << res << '\n';
	return res;
}

bool operator <(const C &left, const C &right)
{
	bool res = left.value() < right.value();
	cout << "    " << left.value()
		<< " < " << right.value();
	cout << " is " << res << '\n';
	return res;
}

#define	TEST(expr)	\
	cout << #expr << '\n';	\
	cout << "        result is " << (expr) << '\n'

typedef	tuple<C &, C &, C &> tuple1;

int main()
{
	C a = 1;
	C b = 2;
	C c = 3;
	C d = 1;
	C e = 4;
	C f = 3;

	cout << boolalpha;
	tuple1 t0(a, b, c);
	tuple1 t1(d, e, f);
	TEST(t0 == t1);
	TEST(t0 != t1);
	TEST(t0 < t1);
	TEST(t0 <= t1);
	TEST(t0 > t1);
	TEST(t0 >= t1);

	return 0;
}
