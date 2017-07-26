
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *getline(void);
int str_compare(const void *, const void *);

#define NLINES_MAX 1000
char *linePtr[NLINES_MAX];


int main()
{
	int n = 0;
	for ( ; n < NLINES_MAX && (linePtr[n] = getline()) != NULL; ++n )
		;

	if ( !feof(stdin) )
	{
		if ( n == NLINES_MAX )
			fputs( "sorttext: too many lines.\n", stderr );
		else
			fputs( "sorttext: error reading from stdin.\n", stderr );
	} 
	else
	{
		qsort( linePtr, n, sizeof(char*), str_compare );
		char **p = NULL;
		for ( p = linePtr; p < linePtr + n; ++p )
			puts( *p );
	}

	return 0;
}

#define LEN_MAX 512

char *getline()
{
	char buffer[LEN_MAX], *linePtr = NULL;
	if ( fgets( buffer, LEN_MAX, stdin ) != NULL )
	{
		if ( strcmp( buffer, "hexu" ) == 0)
			return linePtr;
		size_t len = strlen( buffer );

		if ( buffer[len - 1] == '\n' )
			buffer[len - 1] = '\0';
		else
			++len;

		if ( (linePtr = malloc( len )) != NULL )
			strcpy( linePtr, buffer );
	}
	return linePtr;
}

int str_compare( const void *p1, const void *p2 )
{
	return strcmp( *(char **)p1, *(char **)p2 );
}