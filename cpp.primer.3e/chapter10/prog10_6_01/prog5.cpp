// 通用的模板定义
template <class T>
T max( T t1, T t2 ) {
	return (t1 > t2 ? t1 : t2);
}

#include <cstring>
// const char* 显式特化:
// 覆盖了来自通用模板定义的实例
typedef const char *PCC;
template<> PCC max< PCC >( PCC s1, PCC s2 ) {
	return ( strcmp( s1, s2 ) > 0 ? s1 : s2 );
}

#include <iostream>
// 函数模板 max() 的定义以及对 const char* 的特化
int main() {
	using std::cout;
	using std::endl;
	
	// 调用实例: int max< int >( int, int );
	int i = max( 10, 5 );
	
	// 调用显式特化: const char* max< const char* >( const char*, const char* );
	const char *p = max( "hello", "world" );
	cout << "i: " << i << " p: " << p << endl;
	
	return 0;
}
