/* func.c:  __func__宏获取"包含函数名称"的字符串常量 */

#include <stdio.h>

int test_func( char* s )
{
	if ( s == NULL ) {
		fprintf( stderr,
				"%s: received null pointer argument\n", __func__ );
		return -1;
	}
	else
		return 0;
}


int main()
{
	test_func(NULL);

	return 0;
}
