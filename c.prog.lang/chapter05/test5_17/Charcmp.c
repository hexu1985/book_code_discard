/* Charcmp.c */ 

#include <ctype.h>

#define		FOLD		4		/* fold upper and lower case */ 
#define		DIR			8		/* directory order */

/* charcmp: return <0 if s<t, 0 if s==t, >0 if s>t */
int charcmp(char *s, char *t)
{
	extern char option;		/* Sort.cÖÐ¶¨Òåoption */
	extern int pos1, pos2; 
	char a, b;
	int i, j, endpos;
	
	int fold = (option & FOLD) ? 1 : 0;
	int dir = (option & DIR) ? 1 : 0;
	
	i = j = pos1;
	if (pos2 > 0)
		endpos = pos2;
	else if ((endpos = strlen(s)) > strlen(t))
		endpos = strlen(t);
	do {
		if (dir) 
		{
			while (i < endpos && !isalnum(s[i]) && 
					s[i] != ' ' && s[i] != '\0') 
				i++;
			while (j < endpos && !isalnum(t[j]) && 
					t[j] != ' ' && t[j] != '\0') 
				j++;
		}
		if (i < endpos && j < endpos)
		{
			a = fold ? tolower(s[i]) : s[i];
			i++;
			b = fold ? tolower(t[j]) : t[j];
			j++;
			if (a == b && a == '\0')
				return 0;
		}
	} while (a == b && i < endpos && j < endpos);
	return a - b; 
}
