/* MBSTOWCS.CPP illustrates the behavior of the mbstowcs function
 */

#include <stdlib.h>
#include <stdio.h>

void main( void )
{
    int i;
    char    *pmbnull  = NULL;
    char    *pmbhello = (char *)malloc( MB_CUR_MAX );
    wchar_t *pwchello = L"Hi";
    wchar_t *pwc      = (wchar_t *)malloc( sizeof( wchar_t ));

    printf( "Convert to multibyte string:\n" );
    i = wcstombs( pmbhello, pwchello, MB_CUR_MAX );
    printf( "\tCharacters converted: %u\n", i );
    printf( "\tHex value of first" );
    printf( " multibyte character: %#.4x\n\n", pmbhello );

    printf( "Convert back to wide-character string:\n" );
    i = mbstowcs( pwc, pmbhello, MB_CUR_MAX );
    printf( "\tCharacters converted: %u\n", i );
    printf( "\tHex value of first" );
    printf( " wide character: %#.4x\n\n", pwc );
}
