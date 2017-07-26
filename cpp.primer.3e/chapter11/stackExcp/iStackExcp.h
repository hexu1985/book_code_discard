
#include <vector>

using std::vector;

#include <vector>
class iStack {
public:
	iStack( int capacity ) : _stack( capacity ), _top( 0 ) { }
	void pop( int &top_value );
	void push( int value );
	bool full();
	bool empty();
	
	void display();
	int size();

private:
	int _top;
	vector< int > _stack;
};

inline int iStack::size() {return _top;}

inline bool iStack::empty() 
{
	return _top ? false : true;
}

inline bool iStack::full()
{
	return _top < _stack.size()-1 ? false : true;
}

// 新异常类:
// 负责保存不能被压入到栈中的值
class pushOnFull {
public:
	pushOnFull( int i ) : _value( i ) { }
	int value() { return _value; }

private:
	int _value;
};