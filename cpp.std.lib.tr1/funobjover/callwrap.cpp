#include <iostream>
#include <math.h>

using std::cout;

class wrapper
{
	typedef float (*fp)(float);

public:
	wrapper(fp ptr): fptr(ptr) {}
	float operator ()(float arg)
	{
		return fptr(arg);
	}

private:
	fp fptr;
};

int main()
{
	wrapper wrap(cosf);
	cout << "cosf(1.0) is " << cosf(1.0) << '\n';
	cout << "wrap(1.0) is " << wrap(1.0) << '\n';

	return 0;
}
