#include <algorithm>
#include <vector>
#include <iterator>
#include <iostream>

using namespace std;

class print_elements {
public:
	void operator()( string elem ) 
	{
		cout << elem
			<< ( _line_cnt++ % 8 ? " " : "\n\t" );
	}

	static void reset_line_cnt() { _line_cnt = 1; }

private:
	static int _line_cnt;
};

int print_elements::_line_cnt = 1;

/* 生成:
	原字符本为:
	The light untonsured hair grained and hued like
	pale oak
	copy_backward( begin+1, end-3, end ) 后的序列为:
	The light untonsured hair light untonsured hair grained
	and hued
 */

int main()
{
	string sa[] = {
		"The", "light", "untonsured", "hair",
		"grained", "and", "hued", "like", "pale", "oak" };

	vector< string > svec( sa, sa+10 );

	cout << "original list of strings:\n\t";
	for_each( svec.begin(), svec.end(), print_elements() );
	cout << "\n\n";

	copy_backward( svec.begin()+1, svec.end()-3, svec.end() );

	print_elements::reset_line_cnt();

	cout << "sequence after "
		<< "copy_backward( begin+1, end-3, end ):\n";
	for_each( svec.begin(), svec.end(), print_elements() );
	cout << "\n";

	int arr[] = {0, 1, 2, 3, 4, 5};

	ostream_iterator<int> ofile(cout, " ");

	cout << "arr:\n";
	copy(arr, arr + 6, ofile);
	cout << endl;

	copy_backward(arr, arr + 3, arr + 6);
	cout << "after copy_backward(arr, arr + 3, arr + 6), arr:\n";
	copy(arr, arr + 6, ofile);
	cout << endl;

	return 0;
}
