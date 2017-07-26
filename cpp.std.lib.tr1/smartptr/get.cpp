#include <tr1/memory>
#include <iostream>

using std::tr1::shared_ptr;
using std::cout;

int main()
{
	int *ip = new int(3);
	cout << (void *) ip << '\n';
	shared_ptr<int> sp(ip);
	cout << (void *) sp.get() << '\n';
	shared_ptr<int> sq;
	cout << (void *) sq.get() << '\n';

	return 0;
}
