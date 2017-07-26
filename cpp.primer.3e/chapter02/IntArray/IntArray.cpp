/* ---------->> IntArray.cpp <<---------- */
#include "IntArray.h"
#include <iostream>
#include <algorithm>
#include <new>

void IntArray::init(int sz, int *array) 
{
	_size = sz;
	ia = new int[_size];
	
	for (int ix = 0; ix < _size; ++ix)
		if (!array)
			ia[ix] = 0;
		else
			ia[ix] = array[ix];
} 

IntArray::IntArray(int sz) 
{
	init(sz, 0);
} 

IntArray::IntArray(int *array, int sz)
{
	init(sz, array);
}
 
IntArray::IntArray(const IntArray &rhs)
{
	init(rhs._size, rhs.ia);
}
 
/*
IntArray::IntArray(int sz)
{
	// 设置数据成员
	_size = sz;
	ia = new int[_size];
	
	// 初始化内存
	for (int ix = 0; ix < _size; ++ix)
		ia[ix] = 0;
} 

IntArray::IntArray(int *array, int sz) 
{
	// 设置数据成员
	_size = sz;
	ia = new int[_size];
	
	// 拷贝数据成员
	for (int ix = 0; ix < _size; ++ix)
		ia[ix] = array[ix];
}	

IntArray::IntArray(const IntArray &rhs)		// 拷贝构造函数 
{
	_size = rhs._size;
	ia = new int[_size];
	
	for (int ix = 0; ix < _size; ++ix)
		ia[ix] = rhs.ia[ix];
}
*/

int &IntArray::operator[](int index)
{
	std::cout << "IntArray::operator[]\n";
//	assert(index >= 0 && index < _size);
	return ia[index];
}

bool IntArray::operator!=(const IntArray &rhs) const
{
	return !operator==(rhs);
}

bool IntArray::operator==(const IntArray &rhs) const
{
	if (_size != rhs._size) 
		return false;
	for	(int ix = 0; ix < _size; ++ix)
		if (ia[ix] != rhs.ia[ix]) 
			return false; 
	return true;
}			

int IntArray::max() const 
{
	int *tmp = new int[_size];
	std::copy(ia, ia + _size, tmp);
	std::sort(tmp, tmp + _size);
	return tmp[_size-1];
}

int IntArray::min() const 
{
	int *tmp = new int[_size];
	std::copy(ia, ia + _size, tmp);
	std::sort(tmp, tmp + _size);
	return tmp[0];
}

void IntArray::sort() 
{
	std::sort(ia, ia + _size);
}

int IntArray::find(int value) const 
{
	for (int ix = 0; ix < _size; ++ix) 
		if (ia[ix] == value)
			return ix;
	return -1;
}
 
void swap(IntArray &ia, int i, int j)
{
	int tmp = ia[i];
	ia[i] = ia[j];
	ia[j] = tmp;
}
