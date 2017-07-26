#include <tr1/functional>
#include <iostream>

using std::tr1::bind;
using namespace std::tr1::placeholders;
using std::less;
using std::cout;

template <class Pr>
int count_elements(const int *first, const int *last,
		Pr pred)
{
	int count = 0;
	while (first != last)
		if (pred(*first++))
			++count;
	return count;
}

int count_ge10(int *first, int *last)
{
	int val = 10;
	return count_elements(first, last,
			bind(less<int>(), val, _1));
}

int main()
{
	int values[6] = {1, 3, 19, 12, 6, 11};
	int count = count_ge10(values, values+6);
	cout << count
		<< " values greater than or equal to 10\n";

	return 0;
}


