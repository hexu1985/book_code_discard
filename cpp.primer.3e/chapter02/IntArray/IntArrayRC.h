/* ---------->> IntArrayRC.h <<---------- */
#ifndef	IntArrayRC_H
#define	IntArrayRC_H

#include "IntArray.h"

class IntArrayRC : public IntArray {
public:
	IntArrayRC(int sz = DefaultArraySize);
	IntArrayRC(int *array, int array_size);
	IntArrayRC(const IntArrayRC &rhs);
	
	virtual int &operator[](int);
	
private:
	void check_range(int);
};

#endif		 
