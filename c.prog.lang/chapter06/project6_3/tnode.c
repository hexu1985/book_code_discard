/* addtree.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tnode.h"

/* addtree函数：在p的位置或p的下方增加一个w节点 */
struct tnode *addtree(struct tnode *p, char *w)
{
	int cond;
	char *strup(char *);
	struct tnode *talloc(void);
	
	if (p == NULL) {	/* 该单词是一个新单词 */
		p = talloc();	/* 创建一个新节点 */
		p->word = strup(w);
		p->count = 1;
		p->left = p->right = NULL;
	} else if ((cond = strcmp(w, p->word)) == 0)
		p->count++;		/* 新单词与节点中的单词匹配 */
	else if (cond < 0)	/* 如果小于该节点中的单词，则进左子树 */
		p->left = addtree(p->left, w);
	else				/* 如果大于该节点中的单词，则进右子树 */
		p->right = addtree(p->right, w);
	return p;
}

/* treeprint函数：按序打印树p */
void treeprint(struct tnode *p)
{
	if (p != NULL) {
		treeprint(p->left);
		printf("%4d %s\n", p->count, p->word);
		treeprint(p->right);
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
