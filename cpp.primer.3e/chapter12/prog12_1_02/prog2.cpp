#include <algorithm>
#include <vector>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::find;

int main()
{
	int search_value;
	int ia[ 6 ] = { 27, 210, 12, 47, 109, 83 };
	vector<int> vec( ia, ia+6 );

	cout << "enter search value: ";
	cin >> search_value;

	vector<int>::iterator presult;
	presult = find( vec.begin(), vec.end(), search_value );

	cout << "The value " << search_value
		<< ( presult == vec.end() ? " is not present" : " is present" )
		<< endl;
	
	return 0;
}
