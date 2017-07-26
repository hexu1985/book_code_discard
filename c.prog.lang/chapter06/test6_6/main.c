/* main.c */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "defundef.h"

/* simple version of #define processor */
int main() 
{
	char w[MAXWORD];
	struct nlist *p;
	
	while (getword(w, MAXWORD) != EOF)
		if (strcmp(w, "#") == 0)	/* beginnig of direct. */
			getdef();
		else if (!isalpha(w[0]))
			printf("%s", w);		/* connot be defined */
		else if ((p = lookup(w)) == NULL)
			printf("%s", w);		/* not defined */
		else
			ungets(p->defn);		/* push definition */
	return 0;
}

