
#include <iostream>

#include "ArrayT.h"
#include "ArrayRCT.h"

template <typename elemType>
inline void swap(Array<elemType> &array, int i, int j)
{
	elemType tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}

using namespace std;

int main()
{
	Array<int> ia1;
	ArrayRC<int> ia2;
	cout << "swap() with Array<int> ia1\n";
	int size = ia1.size();
	swap(ia1, 1, size);
	
	cout << "swap() with ArrayRC<int> ia2\n";
	size = ia2.size();
	swap(ia2, 1, size);
	
	return 0;
}
