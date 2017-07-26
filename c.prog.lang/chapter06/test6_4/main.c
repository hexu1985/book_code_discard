/* main.c */

#include <stdio.h>
#include <ctype.h>
#include "tnode.h"

#define	MAXWORD		100

int getword(char *, int);
void sortlist(void);

struct tnode *list[NDISTINCT];		/* pointers to tree nodes */
int ntn = 0;						/* number of tree nodes */

/* print distinct words sorted in decreasing order of freq. */
int main()
{
	struct tnode *root;
	char word[MAXWORD];
	int i;
	
	root = NULL;
	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]))
			root = addtree(root, word);
	treestore(root);
	sortlist();
	for (i = 0; i < ntn; i++)
		printf("%2d:%20s\n", list[i]->count, list[i]->word);
	return 0;
}
