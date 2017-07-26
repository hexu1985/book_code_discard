
#include <iostream>

using std::istream;
using std::ostream;

class String;

istream &operator>>(istream &, String &);
ostream &operator<<(ostream &, const String &);

class String {
public:
	// 一组重载的构造函数
	// 提供自动初始化功能
	// String str1;				// String()
	// String str2("literal");	// String(const char *);
	// String str3(str2);		// String(const String &);
	
	String();
	String(const char *);
	String(const String &);
	
	// 析构函数: 自动析构
	~String();
	
	// 一组重载的赋值操作符
	// str1 = str2;
	// str3 = "a string literal";
	
	String &operator=(const String &);
	String &operator=(const char *);
	
	// 一组重载的等于操作符
	// str1 = str2;
	// str3 = "a string literal";
	
	bool operator==(const String &);
	bool operator==(const char *);
	
	// 重载的下标操作符
	// str1[0] = str2[0];
	
	char &operator[](int);
	
	// 成员访问函数
	int size() {return _size;}
	char *c_str() const {return _string;}
	
private:
	int _size;
	char *_string;
};
