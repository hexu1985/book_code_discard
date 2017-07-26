#include <algorithm>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::find;

int main()
{
	int search_value;
	int ia[ 6 ] = { 27, 210, 12, 47, 109, 83 };

	cout << "enter search value: ";
	cin >> search_value;

	int *presult = find( &ia[0], &ia[6], search_value );
	cout << "The value " << search_value
		<< ( presult == &ia[6] ? " is not present" : " is present" )
		<< endl;
	
	return 0;
}
