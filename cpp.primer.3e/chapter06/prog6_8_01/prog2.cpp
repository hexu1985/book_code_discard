#include <string>
#include <iostream>

int main() {
	using std::string;
	using std::cout;
	using std::endl;
	
	string name( "AnnaBelle" );
	string::size_type pos = name.find( "Anna" );
	if ( pos == string::npos )
		cout << "Anna not found!\n";
	else cout << "Anna found at pos: " << pos << endl;
}
