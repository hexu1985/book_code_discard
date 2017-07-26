#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

template <class Type>
void print_elements( Type elem ) { cout << elem << " "; }

/*
 * 结果:
	ia sorted into two subarrays:
	12 15 17 20 23 26 29 35 40 51 10 16 21 41 44 54 62 65 71 74
	ia inplace_merge:
	10 12 15 16 17 20 21 23 26 29 35 40 41 44 51 54 62 65 71 74
	ivec sorted into two subvectors:
	51 40 35 29 26 23 20 17 15 12 74 71 65 62 54 44 41 21 16 10
	ivec inplace_merge:
	74 71 65 62 54 51 44 41 40 35 29 26 23 21 20 17 16 15 12 10
 */

int main()
{
	int ia[] = { 29,23,20,17,15,26,51,12,35,40,
		74,16,54,21,44,62,10,41,65,71 };
	vector< int > ivec( ia, ia+20 );
	void (*pfi)( int ) = print_elements;
	// 以一事实上排序排列两上子序列
	sort( &ia[0], &ia[10] );
	sort( &ia[10], &ia[20] );
	cout << "ia sorted into two sub-arrays: \n";
	for_each( ia, ia+20, pfi ); cout << "\n\n";

	inplace_merge( ia, ia+10, ia+20 );
	cout << "ia inplace_merge:\n";
	for_each( ia, ia+20, pfi ); cout << "\n\n";

	sort( ivec.begin(), ivec.begin()+10, greater<int>() );
	sort( ivec.begin()+10, ivec.end(), greater<int>() );
	cout << "ivec sorted into two sub-vectors: \n";

	for_each( ivec.begin(), ivec.end(), pfi ); cout << "\n\n";
	inplace_merge( ivec.begin(), ivec.begin()+10,
		ivec.end(), greater<int>() );
	cout << "ivec inplace_merge:\n";
	for_each( ivec.begin(), ivec.end(), pfi ); cout << endl;
	
	return 0;
}
