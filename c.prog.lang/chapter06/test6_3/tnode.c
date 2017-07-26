/* addtree.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tnode.h"

char *strup(char *);
struct tnode *talloc(void);
int compare(char *, struct tnode *, int, int *);
struct linklist *lalloc(void);
void addln(struct tnode *p, int linenum);
	
/* addtree: add a node with w, at or below p */
struct tnode *addtreex(struct tnode *p, char *w, int linenum)
{
	int cond;

	if (p == NULL) {	/* a new word has arrived */
		p = talloc();	/* make a new node */
		p->word = strup(w);
		p->lines = lalloc();
		p->lines->lnum = linenum;
		p->lines->ptr = NULL;
		p->left = p->right = NULL;
	} else if ((cond = strcmp(w, p->word)) == 0)	
		addln(p, linenum);
	else if (cond < 0)
		p->left = addtreex(p->left, w, linenum);
	else 
		p->right = addtreex(p->right, w, linenum);
	return p;
}

/* treexprint: in-order print of tree p if p->match == YES */
void treexprint(struct tnode *p)
{
	struct linklist *temp;
	if (p != NULL) {
		treexprint(p->left);
		printf("%10s: ", p->word);
		for (temp = p->lines; temp != NULL; temp = temp->ptr)
			printf("%4d ", temp->lnum);
		printf("\n");
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

/* addln: add a line number to the linked list */
void addln(struct tnode *p, int linenum)
{
	struct linklist *temp;
	
	temp = p->lines;
	while (temp->ptr != NULL && temp->lnum != linenum)
		temp = temp->ptr;
	if (temp->lnum != linenum) {
		temp->ptr = lalloc();
		temp->ptr->lnum = linenum;
		temp->ptr->ptr = NULL;
	}
}

/* lalloc: make a linklist node */
struct linklist *lalloc(void)
{
	return (struct linklist *) malloc(sizeof(struct linklist));
}
	