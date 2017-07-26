
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

void throwfunc();

int main() 
try {
	int a = 12;
	throwfunc();
	throw a;
	
	return 4;
}
catch(...) {
	cout << "hello in " << __func__ << endl;
}

void throwfunc()
try {
	int b = 3;
	throw b;
}
catch(...) {
	cout << "hello in " << __func__ << endl;
	return;
}