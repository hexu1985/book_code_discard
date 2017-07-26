template <class Type>
class Array { 
public:
	Array(Type *ia, int size_ia) 
	{
		_ia = ia;
		_size = size_ia;
	}
	
	int size() {return _size;}
	
	Type &operator [](int i) { return _ia[i];}
	
protected:
	Type *_ia;
	int _size;
	/* ... */ 
};

template <class Type>
Type min4( Array<Type>& array )
{
	Type min_val = array[0];
	for ( int i = 1; i < array.size(); ++i )
		if ( array[i] < min_val )
			min_val = array[i];

	return min_val;
}

template <class Type>
class ArrayRC : public Array<Type> { 
public:
	ArrayRC(Type *ia, int size_ia) : Array<Type>(ia, size_ia) {}
	
	/* ... */ 
};

int main() {
	int ia[] = { 10, 7, 14, 3, 25 };
	ArrayRC<int> ia_rc( ia, sizeof(ia)/sizeof(int) );
	min4( ia_rc );
	
	return 0;
}
