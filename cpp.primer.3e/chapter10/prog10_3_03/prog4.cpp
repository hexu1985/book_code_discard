template <class T> T min5( T, T ) { /* ... */ }
unsigned int ui;

int main() {
	// 错误: 不能实例化 min5( unsigned int, int )
	// 必须是: min( unsigned int, unsigned int ) 或
	// min( int, int )
	min5( ui, 1024 );

	return 0;
}
