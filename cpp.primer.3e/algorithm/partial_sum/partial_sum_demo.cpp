#include <numeric>
#include <vector>
#include <iostream>
#include <functional>

using namespace std;

/*
 * Êä³ö:
	elements: 1 3 4 5 7 8 9
	partial sum of elements:
	1 4 8 13 20 28 37
	partial sum of elements using times<int>():
	1 3 12 60 420 3360 30240
 */

int main()
{
	const int ia_size = 7;
	int ia[ ia_size ] = { 1, 3, 4, 5, 7, 8, 9 };
	int ia_res[ ia_size ];
	ostream_iterator< int > outfile( cout, " " );
	vector< int > vec( ia, ia+ia_size );
	vector< int > vec_res( vec.size() );

	cout << "elements: ";
	copy( ia, ia+ia_size, outfile ); cout << endl;

	cout << "partial sum of elements:\n";
	partial_sum( ia, ia+ia_size, ia_res );
	copy( ia_res, ia_res+ia_size, outfile ); cout << endl;

	cout << "partial sum of elements using times<int>():\n";
	partial_sum( vec.begin(), vec.end(), vec_res.begin(),
		multiplies<int>() );
	copy( vec_res.begin(), vec_res.end(), outfile );
	cout << endl;

	return 0;
}
