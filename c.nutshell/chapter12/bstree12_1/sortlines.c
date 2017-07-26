/* sortlines.c: */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "BSTree.h"

#define LEN_MAX 1000
char buffer[LEN_MAX];

_Bool printStr( void *str )
{
	return printf( "%s", str) >= 0;
}


int main()
{
	BST_t *pStrTree = newBST( (CmpFunc_t *)strcmp, NULL );
	int n;

	while ( fgets( buffer, LEN_MAX, stdin ) != NULL )
	{
		size_t len = strlen( buffer );
		if ( !BST_insert( pStrTree, buffer, len + 1 ) )
			break;
	}
	if ( !feof( stdin ) )
	{
		fprintf( stderr, "sortlines: "
				 "Error reading or sorting text input.\n" );
		exit( EXIT_FAILURE );
	}
	n = BST_inorder( pStrTree, printStr );

	fprintf( stderr, "\nsortlines: Printed %d lines.\n", n);
	BST_clear( pStrTree );
	return 0;
}