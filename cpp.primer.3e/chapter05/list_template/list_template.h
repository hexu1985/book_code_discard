
template<class elemType>
class list_item {
public:
	list_item( elemType value, list_item *item = 0 ) : _value( value ) 
	{
		if ( !item )
			_next = 0;
		else {
			_next = item->_next;
			item->_next = this;
		}
	}
	
	elemType value() { return _value; }	
	list_item* next() { return _next; }	
	void next( list_item *link ) { _next = link; }	
	void value( elemType new_value ) { _value = new_value; }
	
private:
	elemType _value;
	list_item *_next;
};

template<class elemType>
class list {
public:
	list() : _at_front( 0 ), _at_end( 0 ), _current( 0 ), _size( 0 ) {}
	list( const list& );
	list& operator=( const list& );
	~list() { remove_all(); }

	void insert( list_item<elemType> *ptr, elemType value );
	void insert_end( elemType value );
	void insert_front( elemType value );
	void insert_all( const list &rhs );
	int remove( elemType value );
	void remove_front();
	void remove_all();

	list_item<elemType> *find( elemType value );
	list_item<elemType> *next_iter();
	list_item<elemType> *init_iter( list_item<elemType> *it );
	
	void display( ostream &os = cout );
	void concat( const list& );
	void reverse();
	int size() { return _size; }

private:
	void bump_up_size() { ++_size; }
	void bump_down_size() { --_size; }
	
	list_item<elemType> *_at_front;
	list_item<elemType> *_at_end;
	list_item<elemType> *_current;
	
	int _size;
};