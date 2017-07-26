#include <algorithm>
#include <vector>
#include <string>
#include <iterator>
#include <iostream>

using namespace std;

template <class Type>
void print_elements( Type elem ) { cout << elem << " "; }

void (*pfi)( int ) = print_elements;
void (*pfs)( string ) = print_elements;

int main()
{
	int ia[] = { 0, 1, 0, 2, 0, 3, 0, 4, 0, 5 };
	vector<int> vec( ia, ia+10 );
	vector<int>::iterator vec_iter;

	// 生成不能交换的序列: 没有连续的 0
	// 结果: 0 1 0 2 0 3 0 4 0 5
	vec_iter = unique( vec.begin(), vec.end() );
	for_each( vec.begin(), vec.end(), pfi ); cout << "\n\n";

	// 排了序的向量: 0 0 0 0 0 1 2 3 4 5
	// 应用 unique() 后:
	// 结果: 0 1 2 3 4 5 2 3 4 5
	sort( vec.begin(), vec.end() );
	vec_iter = unique( vec.begin(), vec.end() );
	for_each( vec.begin(), vec.end(), pfi ); cout << "\n\n";

	// 从容器中删除无效元素
	// 结果: 0 1 2 3 4 5
	vec.erase( vec_iter, vec.end() );
	for_each( vec.begin(), vec.end(), pfi ); cout << "\n\n";

	string sa[] = { "enough", "is", "enough",
		"enough", "is", "good"
	};
	vector<string> svec( sa, sa+6 );
	vector<string> vec_result( svec.size() );
	vector<string>::iterator svec_iter;
	sort( svec.begin(), svec.end() );
	svec_iter = unique_copy( svec.begin(), svec.end(),
		vec_result.begin() );
	// 结果: enough good is
	for_each( vec_result.begin(), svec_iter, pfs );
	cout << "\n\n";

	return 0;
}
