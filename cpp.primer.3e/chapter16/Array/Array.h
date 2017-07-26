
#ifndef ARRAY_H
#define ARRAY_H
#include <cassert>
#include <iostream>
using std::cout;
using std::ostream;
using std::endl;

template <class elemType> class Array;

template <class elemType> ostream&
operator<< ( ostream &, const Array<elemType> & );

template <class elemType>
class Array {
public:
	explicit Array( int sz = DefaultArraySize )
	{ init( 0, sz ); }
	
	Array( const elemType *ar, int sz )
	{ init( ar, sz ); }
	
	Array( const Array &iA )
	{ init( iA._ia, iA._size ); }
	
	~Array() { delete[] _ia; }
	
	Array & operator=( const Array & );
	
	int size() const { return _size; }
	
	elemType& operator[]( int ix ) const
	{ return _ia[ix]; }
	
	ostream &print( ostream &os = cout ) const;
	
	void grow();
	void sort( int,int );
	int find( elemType );
	elemType min();
	elemType max();

private:
	void init( const elemType *, int );
	void swap( int, int );
	static const int DefaultArraySize = 12;
	int _size;
	elemType *_ia;
};
#endif

template <class elemType>
void Array<elemType>::init( const elemType *array, int sz )
{
    _size = sz;
    _ia = new elemType[ _size ];
    for ( int ix = 0; ix < _size; ++ix )
        if ( ! array )
            _ia[ ix ] = elemType();
        else _ia[ ix ] = array[ ix ];
}

template <class elemType> Array<elemType>&
Array<elemType>::operator=( const Array<elemType> &iA )
{
    if ( this != &iA ) {
        delete[] _ia;
        init( iA._ia, iA._size );
    }
    return *this;
}

template <class elemType> ostream&
operator<< ( ostream &os, const Array<elemType> &ar )
{
    return ar.print( os );
}

template <class elemType>
ostream & Array<elemType>::print( ostream &os ) const
{
    const int lineLength = 12;
    os << "( " << _size << " )< ";
    for ( int ix = 0; ix < _size; ++ix )
    {
        if ( ix % lineLength == 0 && ix )
            os << "\n\t";
        os << _ia[ ix ];
        // 对于一行的最后一个元素或者数组的
        // 最后一个元素不产生逗号
        if ( ix % lineLength != lineLength-1 && ix != _size -1 )
            os << ", ";
    }
    os << " >\n";
    return os;
}

template <class elemType>
void Array<elemType>::grow()
{
    elemType *oldia = _ia;
    int oldSize = _size;
    _size = oldSize + oldSize/2 + 1;
    _ia = new elemType[_size];
    int ix;
    for ( ix = 0; ix < oldSize; ++ix)
        _ia[ix] = oldia[ix];
    for ( ; ix < _size; ++ix )
        _ia[ix] = elemType();
    delete[] oldia;
}

template <class elemType>
elemType Array<elemType>::min( )
{
    assert( _ia != 0 );
    elemType min_val = _ia[0];
    for ( int ix = 1; ix < _size; ++ix )
       if ( _ia[ix] < min_val )
            min_val = _ia[ix];
    return min_val;
}

template <class elemType>
elemType Array<elemType>::max()
{
    assert( _ia != 0 );
    elemType max_val = _ia[0];
    for ( int ix = 1; ix < _size; ++ix )
        if ( max_val < _ia[ix] )
           max_val = _ia[ix];
    return max_val;
}

template <class elemType>
int Array<elemType>::find( elemType val )
{
    for ( int ix = 0; ix < _size; ++ix )
        if ( val == _ia[ix] ) return ix;
    return - 1;
}

template <class elemType>
void Array<elemType>::swap( int i, int j )
{
    elemType tmp = _ia[i];
    _ia[i] = _ia[j];
    _ia[j] = tmp;
}

template <class elemType>
void Array<elemType>::sort( int low, int high )
{
    if ( low >= high ) return;
    int lo = low;
    int hi = high + 1;
    elemType elem = _ia[low];
    for (;;) {
        while ( _ia[++lo] < elem && lo < high ) ;
        while ( _ia[--hi] > elem && hi > low ) ;
        if ( lo < hi )
            swap( lo, hi );
        else break;
    }
    swap( low, hi );
    sort( low, hi-1 );
    sort( hi+1, high );
}

template <class elemType>
void try_array( Array<elemType> &iA )
{
    cout << "try_array: initial array values:\n";
    cout << iA << endl;
    elemType find_val = iA [ iA.size()-1 ];
    iA[ iA.size()-1 ] = iA.min();
    int mid = iA.size()/2;
    iA[0] = iA.max();
    iA[mid] = iA[0];
    cout << "try_array: after assignments:\n";
    cout << iA << endl;
    
    Array<elemType> iA2 = iA;
    iA2[mid/2] = iA2[mid];
    cout << "try_array: memberwise initialization\n";
    cout << iA << endl;
    iA = iA2;
    cout << "try_array: after memberwise copy\n";
    cout << iA << endl;
    iA.grow();
    cout << "try_array: after grow\n";
    cout << iA << endl;
    
    int index = iA.find( find_val );
    cout << "value to find: " << find_val;
    cout << "\tindex returned: " << index << endl;
    
    elemType value = iA[index];
    cout << "value found at index: ";
    cout << value << endl;
}

