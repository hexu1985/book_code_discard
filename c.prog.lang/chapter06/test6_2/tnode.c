/* addtree.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tnode.h"

/* addtree: add a node with w, at or below p */
struct tnode *addtreex(struct tnode *p, char *w, int num, int *found)
{
	int cond;
	char *strup(char *);
	struct tnode *talloc(void);
	int compare(char *, struct tnode *, int, int *);
	
	if (p == NULL) {	/* a new word has arrived */
		p = talloc();	/* make a new node */
		p->word = strup(w);
		p->match = *found;
		p->left = p->right = NULL;
	} else if ((cond = compare(w, p, num, found)) < 0) 	/* 如果小于该节点中的单词，则进左子树 */
		p->left = addtreex(p->left, w, num, found);
	else if (cond > 0) 				/* 如果大于该节点中的单词，则进右子树 */
		p->right = addtreex(p->right, w, num, found);

	return p;
}

/* treexprint: in-order print of tree p if p->match == YES */
void treexprint(struct tnode *p)
{
	if (p != NULL) {
		treexprint(p->left);
		if (p->match)
			printf("%s\n", p->word); 
		treexprint(p->right);
	}
}

/* talloc函数：创建一个tnode */
struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}

char *strup(char *s)	/* 复制s到某个位置*/
{
	char *p;
	
	p = (char *) malloc(strlen(s)+1);		/* 执行加1操作是为了在结尾加上字符'\0' */
	if (p != NULL)
		strcpy(p, s);
	return p;
}

/* compare: compare words and update p->match */
int compare(char *s, struct tnode *p, int num, int *found)
{
	int i;
	char *t = p->word;
	
	for (i = 0; *s == *t; i++, s++, t++)
		if (*s == '\0')
			return 0;
	if (i >= num) {		/* identical in first num chars ? */
		*found = YES;
		p->match = YES;
	}
	return *s - *t;
}
