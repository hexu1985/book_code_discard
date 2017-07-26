template <class Type>
// 第一个参数是 Type*
Type min2( Type* array, int size )
{
	Type min_val = array[0];
	for ( int i = 1; i < size; ++i )
		if ( array[i] < min_val )
			min_val = array[i];

	return min_val;
}

int ai[4] = { 12, 8, 73, 45 };

int main() {
	int size = sizeof (ai) / sizeof (ai[0]);
	
	// ok: 从数组到指针的转换
	min2( ai, size );
	
	return 0;
}
