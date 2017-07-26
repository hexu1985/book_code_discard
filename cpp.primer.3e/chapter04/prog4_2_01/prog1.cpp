/* prog1.cpp */
/* on page 119 of C++ Primer 3e */

#include <iostream>

int main() {
	using std::cout;
	using std::endl;
	
	char byte_value = 32;
	int ival = 8;
	// overflow of byte_value's available memory
	byte_value = ival * byte_value;
	cout << "byte_value: " << static_cast<int>(byte_value) << endl;
}
