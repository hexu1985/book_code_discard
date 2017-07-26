/* main.c */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "tnode.h"

#define MAXWORD	100

int getword(char *, int);

/* print in alphabetic order each group of variable names */
/* identical in the first num characters (default 6) */
int main(int argc, char *argv[])
{
	struct tnode *root;
	char word[MAXWORD];
	int found = NO;		/* YES if match was found */
	int num;			/* number of the first ident. char */
	
	num = (--argc && (*++argv)[0] == '-') ? atoi(argv[0]+1) : 6;
	
	root = NULL;
	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]) && strlen(word) >= num)
			root = addtreex(root, word, num, &found);
	treexprint(root);
	return 0;
}
