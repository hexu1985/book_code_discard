/* ---------->> IntArray.h <<---------- */
#ifndef	INTARRAY_H
#define	INTARRAY_H

class IntArray {
public:
	// 构造函数
	explicit IntArray(int sz = DefaultArraySize);
	IntArray(int *array, int array_size); 
	IntArray(const IntArray &rhs); 
	
	// 析构函数
	~IntArray() {delete[] ia;}
	
	// 相等于不相等操作: #2b
	bool operator==(const IntArray&) const;
	bool operator!=(const IntArray&) const;
	
	// 下标操作符
	virtual int &operator[](int index);
	
	// 赋值操作符: #2b
	IntArray& operator=(const IntArray&);
	virtual int size() const { return _size; }	// #1 
	virtual void sort();		// #4
	virtual int min() const;	// #3a
	virtual int max() const;	// #3b
	
	// 如果在数组中找到
	// 返回第一次出现的索引
	// 否则返回-1
	virtual int find(int value) const;	// #3c
	
protected:
	// 私有实现代码
	static const int DefaultArraySize = 12; 
	void init(int sz, int *array); 
	// 内部数据 
	int _size;
	int *ia; 
};	 
	 
#endif

