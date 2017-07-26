/* ISWALPHA.c */

#include <stdio.h>
#include <ctype.h>
#include <locale.h>


int main()
{
	wint_t wc;

	if ( setlocale( LC_CTYPE, "") == NULL )
	{
		fwprintf( stderr,
				  L"Sorry, couldn't change to the the system's native locale.\n" );
		return 1;
	}
	wprintf( L"The current locale for the 'isw ...' functions is '%s'.\n", 
			 setlocale( LC_CTYPE, NULL ) );

	wprintf( L"Here is a table of the 'isw ...' values for the characters "
			 L"from 128 to 255 in this locale\n\n");

	for ( wc = 128; wc < 255; ++wc )
	{
		if ( (wc - 128) % 24 == 0 )
		{
			wprintf( L"Code char alnum alpha cntrl digit graph lower" 
					 L" print punct space upper xdigit\n" );
			wprintf( L"---------------------------------------------"
					 L"-------------------------------\n" );
		}
		wprintf( L"%4u %4lc %3c %5c %5c %5c %5c %5c %5c %5c %5c %5c %5c\n",
				 wc, 
				 ( iswprint( wc ) ? wc : ' ' ), 
				 ( iswalnum( wc ) ? wc : ' ' ), 
				 ( iswalpha( wc ) ? wc : ' ' ), 
				 ( iswcntrl( wc ) ? wc : ' ' ), 
				 ( iswdigit( wc ) ? wc : ' ' ), 
				 ( iswgraph( wc ) ? wc : ' ' ), 
				 ( iswlower( wc ) ? wc : ' ' ), 
				 ( iswprint( wc ) ? wc : ' ' ), 
				 ( iswpunct( wc ) ? wc : ' ' ), 
				 ( iswspace( wc ) ? wc : ' ' ), 
				 ( iswupper( wc ) ? wc : ' ' ), 
				 ( iswxdigit( wc ) ? wc : ' ' ) );
	}

	return 0;
}