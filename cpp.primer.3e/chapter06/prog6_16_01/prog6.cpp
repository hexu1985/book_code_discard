#include <stack>
#include <iostream>

using std::stack;
using std::cout;
using std::cerr;
using std::endl;

int main()
{
	const int ia_size = 10;
	int ia[ia_size ] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	// Ìî³ä stack
	int ix = 0;
	stack< int > intStack;
	for ( ; ix < ia_size; ++ix )
		intStack.push( ia[ ix ] );

	int error_cnt = 0;
	if ( intStack.size() != ia_size ) {
		cerr << "oops! invalid intStack size: "
			<< intStack.size()
			<< "\t expected: " << ia_size << endl;
		++error_cnt;
	}

	int value;
	while ( intStack.empty() == false )
	{
		// ¶ÁÈ¡Õ»¶¥ÔªËØ
		value = intStack.top();
	
		if ( value != --ix ) {
			cerr << "oops! expected " << ix
				<< " received " << value
				<< endl;
			++error_cnt;
		}
	
		// µ¯³öÕ»¶¥ÔªËØ, ²¢ÖØ¸´
		intStack.pop();
	}

	cout << "Our program ran with "
		<< error_cnt << " errors!" << endl;
	
	return 0;
}
