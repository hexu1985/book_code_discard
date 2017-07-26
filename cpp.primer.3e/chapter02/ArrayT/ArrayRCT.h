
#ifndef	ArrayRC_H
#define	ArrayRC_H

#include "ArrayT.h"
#include <cassert>

template <typename elemType>
class ArrayRC : public Array<elemType> {
public:
	ArrayRC(int sz = Array<elemType>::DefaultArraySize)	
		: Array<elemType>(sz) {}
		
	ArrayRC(elemType *ia, int sz)
		: Array<elemType>(ia, sz) {}
		
	ArrayRC(const ArrayRC &rhs)
		: Array<elemType>(rhs) {}
	
	elemType &operator[](int index)
	{
		assert(index >= 0 && index < Array<elemType>::size());
		return ia[index];
	}
	
private:
	// ...
};

#endif
