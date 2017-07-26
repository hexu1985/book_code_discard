#include <tr1/memory>
#include <iomanip>
#include <iostream>

using std::tr1::shared_ptr;
using std::cout;
using std::boolalpha;

typedef shared_ptr<int> spi;

int main()
{
	cout << boolalpha;
	spi sp0;
	cout << "empty object: " << sp0.unique() << '\n';
	spi sp1((int *) 0);
	cout << "null pointer: " << sp1.unique() << '\n';
	spi sp2(new int);
	cout << "one object: " << sp2.unique() << '\n';
	{
		spi sp3(sp2);
		cout << "two object: " << sp2.unique() << '\n';
	}
	cout << "one object: " << sp2.unique() << '\n';
	return 0;
}
