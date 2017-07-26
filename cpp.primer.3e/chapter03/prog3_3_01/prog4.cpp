#include <iostream>

const char *st = "The expense of spirit\n";

int main() {
	using std::cout;
	int len = 0;
	while ( *st++ ) ++len;
	st = st - len - 1;
	cout << len << "; " << st;
	return 0;
}
