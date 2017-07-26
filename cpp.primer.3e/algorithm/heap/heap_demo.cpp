#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

template <class Type>
void print_elements( Type elem ) { cout << elem << " "; }

int main()
{
	int ia[] = {29,23,20,22,17,15,26,51,19,12,35,40 };
	vector< int > vec( ia, ia+12 );

	// 结果: 51 35 40 23 29 20 26 22 19 12 17 15
	make_heap( &ia[0], &ia[12] );
	void (*pfi)( int ) = print_elements;
	for_each( ia, ia+12, pfi ); cout << "\n\n";

	// 结果: 12 17 15 19 23 20 26 51 22 29 35 40
	// a min-heap: root is smallest element
	make_heap( vec.begin(), vec.end(), greater<int>() );
	for_each( vec.begin(), vec.end(), pfi ); cout << "\n\n";

	// 结果: 12 15 17 19 20 22 23 26 29 35 40 51
	sort_heap( ia, ia+12 );
	for_each( ia, ia+12, pfi ); cout << "\n\n";

	// 再加一个新的最小的元素:
	vec.push_back( 8 );
	// 结果: 8 17 12 19 23 15 26 51 22 29 35 40 20
	// 将最新最小的元素放在根处
	push_heap( vec.begin(), vec.end(), greater<int>() );
	for_each( vec.begin(), vec.end(), pfi ); cout << "\n\n";

	// 结果: 12 17 15 19 23 20 26 51 22 29 35 40 8
	// 应用次最小的元素替代最小的
	pop_heap( vec.begin(), vec.end(), greater<int>() );
	for_each( vec.begin(), vec.end(), pfi ); cout << "\n\n";

	return 0;
}
