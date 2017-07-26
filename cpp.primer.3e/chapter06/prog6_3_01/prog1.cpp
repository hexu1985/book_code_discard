#include <vector>
#include <iostream>

int main()
{
	using std::vector;
	using std::cout;
	using std::endl;
	
	vector< int > ivec;
	cout << "ivec: size: " << ivec.size()
		<< " capacity: " << ivec.capacity() << endl;
	for ( int ix = 0; ix < 24; ++ix ) {
		ivec.push_back( ix );
		cout << "ivec: size: " << ivec.size()
			<< " capacity: " << ivec.capacity() << endl;
	}
}
