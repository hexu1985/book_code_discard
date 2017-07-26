/* -------------->> ArrayT.h <<-------------- */
#ifndef	ArrayT_H
#define	ArrayT_H

template <typename elemType>
class Array {
public:
	// 把元素类型参数化
	explicit Array(int size = DefaultArraySize);
	Array(elemType *array, int array_size);
	Array(const Array &rhs);
	
	virtual ~Array() {delete[] ia;}	
	
	bool operator==(const Array&) const;
	bool operator!=(const Array&) const;
	
	Array & operator=(const Array&);
	int size() const {return _size;}
	
	virtual elemType &operator[](int index) {return ia[index];}
/*	virtual void sort();
	
	virtual elemType min() const;
	virtual elemType max() const;
	virtual int find(const elemType &value) const;
	*/
protected:
	void init(int sz, elemType *array);
	static const int DefaultArraySize = 12;
	
	int _size;
	elemType *ia;
};	 

template <typename elemType>
void Array<elemType>::init(int sz, elemType *array) 
{
	_size = sz;
	ia = new elemType[_size];
	
	for (int ix = 0; ix < _size; ++ix)
		if (!array)
			ia[ix] = 0;
		else
			ia[ix] = array[ix];
} 

template <typename elemType>
Array<elemType>::Array(int sz) 
{
	init(sz, 0);
} 

template <typename elemType>
Array<elemType>::Array(elemType *array, int sz)
{
	init(sz, array);
}
 
template <typename elemType>
Array<elemType>::Array(const Array<elemType> &rhs)
{
	init(rhs._size, rhs.ia);
}

#endif
