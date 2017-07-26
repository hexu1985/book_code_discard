
#include <iostream>
#include <string>

int main() {
	using std::string;
	using std::cout;
	using std::endl;
	
	string name( "AnnaLiviaPlurabelle" );
	
	cout << "[" << __FILE__ << ":" << __LINE__ << ":" << __func__ << "]"
		<< ", name = [" << name << "]" << endl;
	
	typedef string::size_type size_type;
	size_type startPos = name.find( 'L' );
	size_type endPos = name.find_last_of( 'a' );
	
	name.erase(name.begin() + endPos);
	cout << "[" << __FILE__ << ":" << __LINE__ << ":" << __func__ << "]"
		<< ", name = [" << name << "]" << endl;
		
	name.erase( name.begin()+startPos, name.begin()+endPos );
	cout << "[" << __FILE__ << ":" << __LINE__ << ":" << __func__ << "]"
		<< ", name = [" << name << "]" << endl;
	
	return 0;
}
