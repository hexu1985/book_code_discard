
#include <cstring>
#include <cassert>
#include <iomanip>
#include "String.h"

using std::istream;
using std::ostream;

// 缺省构造函数
//inline 
String::String()
{
	_size = 0;
	_string = 0;
}

//inline 
String::String(const char *str)
{
	if (!str) {
		_size = 0;
		_string = 0;
	} else {
		_size = strlen(str);
		_string = new char[_size+1];
		strcpy(_string, str);
	}
}

// 拷贝构造函数
//inline 
String::String(const String &rhs)
{
	_size = rhs._size;
	if (!rhs._string)
		_string = 0;
	else {
		_string = new char[_size+1];
		strcpy(_string, rhs._string);
	}
}

//inline 
String::~String()
{
	delete [] _string;
}

//inline 
String &String::operator=(const char *s)
{
	if (!s) {
		_size = 0;
		delete [] _string;
		_string = 0;
	} else {
		_size = strlen(s);
		delete [] _string;
		_string = new char[_size+1];
		strcpy(_string, s);
	}
	return *this;
}

//inline 
String &String::operator=(const String &rhs)
{
	if (this != &rhs) {
		delete [] _string;
		_size = rhs._size;
		
		if (!rhs._string)
			_string = 0;
		else {
			_string = new char[_size+1];
			strcpy(_string, rhs._string);
		}
	}
	return *this;
}

//inline 
bool String::operator==(const String &rhs)
{
	if (_size != rhs._size)
		return false;
	return strcmp(_string, rhs._string) ? false : true;
}

//inline 
bool String::operator==(const char *s)
{
	return strcmp(_string, s) ? false : true;
}

//inline 
char &String::operator[](int elem)
{
	assert(elem >= 0 && elem < _size);
	return _string[elem];
}

//inline 
istream &operator>>(istream &is, String &s)
{
	// 人工限制最多4096个字符
	const int limit_string_size = 4096;
	char inBuf[limit_string_size];
	
	// setw()是iostream库的一部分
	// 限制被读取的字符个数为limit_string_size-1
	using std::setw;
	is >> setw(limit_string_size) >> inBuf;
	
	s = inBuf;	// String::operator=(const char *);
	return is;
}

//inline 
ostream &operator<<(ostream &os, const String &s)
{
	return os << s.c_str();
}
