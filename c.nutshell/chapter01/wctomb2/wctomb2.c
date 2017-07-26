/* WCTOMB.CPP illustrates the behavior of the wctomb function */ 

#include <stdio.h>
#include <stdlib.h>

void main( void )
{
   int i;
   wchar_t wc = L'a';
   char *pmbnull = NULL;
   char *pmb = (char *)malloc( sizeof( char ) );

   printf( "Convert a wide character:\n" );
   i = wctomb( pmb, wc );
   printf( "\tCharacters converted: %u\n", i );
   printf( "\tMultibyte character: %.1s\n\n", pmb );

   printf( "Attempt to convert when target is NULL:\n" );
   i = wctomb( pmbnull, wc );
   printf( "\tCharacters converted: %u\n", i );
   printf( "\tMultibyte character: %.1s\n", pmbnull );
}


