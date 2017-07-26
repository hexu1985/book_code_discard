/* MBLEN.C illustrates the behavior of the mblen function
 */

#include <stdlib.h>
#include <stdio.h>

void main( void )
{
    int      i;
    char    *pmbc = (char *)malloc( sizeof( char ) );
    wchar_t  wc   = L'a';

    printf( "Convert wide character to multibyte character:\n" );
    i = wctomb( pmbc, wc );
    printf( "\tCharacters converted: %u\n", i );
    printf( "\tMultibyte character: %x\n\n", pmbc );

    i = mblen( pmbc, MB_CUR_MAX );
    printf( "Length in bytes of multibyte character %x: %u\n", pmbc, i );

    pmbc = NULL;
    i = mblen( pmbc, MB_CUR_MAX );
    printf( "Length in bytes of NULL multibyte character %x: %u\n", pmbc, i );
}
