/* ISWALNUM */

#include <ctype.h>
#include <stdio.h>
#include <locale.h>

int main()
{
	wint_t wc, i;
	int j, dummy;

	setlocale( LC_CTYPE, "" );

	wprintf( L"\nThe current locale for the 'is ...' functions is '%s'. \n", 
			 setlocale( LC_CTYPE, NULL ) );
	wprintf( L"\nThese are the alphanumeric wide characters"
			 L" in this locale:\n\n" );

	for ( wc = 0, i = 0; wc < 1024; wc++ )
		if ( iswalnum( wc ) )
		{
			if ( i % 20 == 0 )
			{
				wprintf( L"\n... more ...\n" );
				dummy = getchar();
				wprintf( L"Wide charcter      Code\n" );
				wprintf( L"-----------------------\n" );
			}
			wprintf( L"%5lc %16lu\n", wc, wc );
			i++;
		}
		wprintf( L"-----------------------\n" );
		return 0;
}