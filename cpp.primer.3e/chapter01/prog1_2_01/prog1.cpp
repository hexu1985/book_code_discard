/* prog.cpp */
/* on page 6 of C++ Primer 3e */

#include <iostream>

using std::cout;

void readIn() { cout << "readIn()\n"; }
void sort() { cout << "sort()\n"; }
void compact() { cout << "compact()\n"; }
void print() { cout << "print()\n"; }

int main()
{
	readIn();
	sort();
	compact();
	print();
	
	return 0;
}
