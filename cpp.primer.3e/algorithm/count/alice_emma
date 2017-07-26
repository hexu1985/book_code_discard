#include <algorithm>
#include <string>
#include <list>
#include <iterator>
#include <cassert>
#include <iostream>
#include <fstream>

using namespace std;

/**************************************************************
* text read:
Alice Emma has long flowing red hair. Her Daddy says
when the wind blows through her hair, it looks almost alive,
like a fiery bird in flight. A beautiful fiery bird, he tells her,
magical but untamed. "Daddy, shush, there is no such thing,"
she tells him, at the same time wanting him to tell her more.
Shyly, she asks, "I mean, Daddy, is there?"
****************************************************************
* 程序输出:
* count(): fiery occurs 2 times
****************************************************************
*/

int main()
{
	ifstream infile( "alice_emma" );
	assert ( infile != 0 );

	list<string> textlines;
	typedef list<string>::difference_type diff_type;
	istream_iterator< string > instream( infile ), eos;

	copy( instream, eos, back_inserter( textlines ));
	string search_item( "fiery" );

	/************************************************************
	 * 注意: 这是使用 count() 的标准 C++ 接口
	 * 但是目前的 RogueWave 实现
	 * 支持的是早期版本, 其中没有开发 distance_type
	 * 因此 count() 将通过
	 * 一个参数返回值
	 *
	 * 调用方式如下:
	 * typedef iterator_traits<InputIterator>::
	 * distance_type dis_type;
	 *
	 * dis_type elem_count;
	 * elem_count = count( textlines.begin(), textlines.end(),
	 * search_item );
	 ************************************************************/

	int elem_count = 0;
	list<string>::iterator
	ibegin = textlines.begin(),
	iend = textlines.end();

	// count() 的过时形式
	count( ibegin, iend, search_item );

	cout << "count(): " << search_item
		<< " occurs " << elem_count << " times\n";
	return 0;
}
