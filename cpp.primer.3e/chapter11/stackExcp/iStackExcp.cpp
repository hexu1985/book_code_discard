
#include <iostream>
#include "iStackExcp.h"

using std::endl;
using std::cout;

void iStack::pop( int &top_value )
{
	if ( empty() )
		throw popOnEmpty();
	top_value = _stack[ --_top ];
	cout << "iStack::pop(): " << top_value << endl;
}

void iStack::push( int value )
{
	cout << "iStack::push( " << value << " ) \n";
	if ( full() )
		throw pushOnFull();
	_stack[ _top++ ] = value;
}

void iStack::display()
{
	if (!size()) {
		cout << "( 0 )\n";
		return;
	}
	cout << "( " << size() << " )( bot: ";
	for (int ix = 0; ix < _top; ++ix)
		cout << _stack[ix] << " ";
	cout << " :top )\n";
}
