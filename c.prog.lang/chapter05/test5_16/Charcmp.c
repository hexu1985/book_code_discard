/* Charcmp.c */ 

#include <ctype.h>

#define		FOLD		4		/* fold upper and lower case */ 
#define		DIR			8		/* directory order */

/* charcmp: return <0 if s<t, 0 if s==t, >0 if s>t */
int charcmp(char *s, char *t)
{
	extern char option;		/* Sort.c÷–∂®“Âoption */ 
	char a, b;
	int fold = (option & FOLD) ? 1 : 0;
	int dir = (option & DIR) ? 1 : 0;
	
	do {
		if (dir) 
		{
			while (!isalnum(*s) && *s != ' ' && *s != '\0') 
				s++;
			while (!isalnum(*t) && *t != ' ' && *t != '\0') 
				t++;
		}
		a = fold ? tolower(*s) : *s;
		s++;
		b = fold ? tolower(*t) : *t;
		t++;
		if (a == b && a == '\0')
			return 0;
	} while (a == b);
	return a - b; 
}
