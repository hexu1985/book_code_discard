#include <iostream>
#include "IntArray.h"
#include "IntArrayRC.h"

extern void swap(IntArray&, int, int);

using namespace std;

int main(int argc, char *argv[])
{
	int array[4] = {0, 1, 2, 3};
	IntArray ia1(array, 4);
	IntArrayRC ia2(array, 4);
	
	// 错误: 一位偏移(off-by-one): 应该是size-1
	// IntArray 对象捕捉不到这个错误
	cout << "swap() with IntArray ia1\n";
	swap(ia1, 1, ia1.size() - 1);
	
	cout << "swap() with IntArray ia2\n";
	swap(ia2, 1, ia2.size() - 1);
	
    system("PAUSE");
    return EXIT_SUCCESS;
}
