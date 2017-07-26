
#include <iostream>

using namespace std;

class test {
public:
	test() : count(count_class)
	{
		count_class++;
		cout << "test::" << __func__ << " called, " 
			<< "test::count=[" << count << "]"
			<< "test::count_class=[" << count_class << "]"
			<< endl;
		cout << std::hex << this << endl;
	}
	
private:
	static int count_class;
	int count;
};

int test::count_class = 0;

int main()
{
	for (int i = 0; i <= 20; i++) {
		test a;
	}
}