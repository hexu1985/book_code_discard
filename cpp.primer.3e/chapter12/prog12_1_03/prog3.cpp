#include <algorithm>
#include <list>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::list;

int main()
{
	int search_value;
	int ia[ 6 ] = { 27, 210, 12, 47, 109, 83 };
	list<int> ilist( ia, ia+6 );

	cout << "enter search value: ";
	cin >> search_value;

	list<int>::iterator presult;
	presult = find( ilist.begin(), ilist.end(), search_value );
	cout << "The value " << search_value
		<< ( presult == ilist.end()	? " is not present" : " is present" )
		<< endl;

	return 0;
}
