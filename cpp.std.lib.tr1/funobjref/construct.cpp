#include <tr1/functional>
#include <iostream>

using std::tr1::reference_wrapper;
using std::cout;

int main()
{
	int Stuhldreher = 3;
	reference_wrapper<int> rw(Stuhldreher);

	cout << rw << '\n';
	Stuhldreher = 4;
	cout << rw << '\n';
	rw.get() = 5;
	cout << Stuhldreher << '\n';

	return 0;
}	
