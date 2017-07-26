/* main.c */

#include <stdio.h>
#include <ctype.h>
#include "tnode.h"

#define MAXWORD	100

int getword(char *, int);
int noiseword(char *w);

/* 单词出现频率的统计 */
int main()
{
	struct tnode *root;
	char word[MAXWORD];
	int linenum = 1;
	
	root = NULL;
	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]) && noiseword(word) == -1)
			root = addtreex(root, word, linenum);
	treexprint(root);
	return 0;
}