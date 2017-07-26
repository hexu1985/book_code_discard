/* strcons.c:  ×Ö·û´®×ÖÃæÁ¿ */

#include <stdio.h>


int main()
{
	int c = '\xA3';
	printf( "Character: %c		Code: %d\n", c, c );

	char doc_path[128] = ".\\share\\doc";
	printf( "\aSee the documentation in the directory \"%s\"\n", doc_path );

	return 0;
}