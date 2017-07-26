/* wctomb.c:  获得字符的多字节表示方式 */
/* wctomb = wide character to multibyte */

#include <stdlib.h>
#include <stdio.h>


int main()
{
	wchar_t wc = L'\x3B1';
	char mbStr[10] = " ";
	int nBytes = 0;
	nBytes = wctomb( mbStr, wc );
	printf("nBytes = %d", nBytes);

	return 0;
}