/* tnode.h */

struct tnode {				/* 树的节点 */
	char *word;				/* 指向单词的指针 */
	int count;				/* 单词出现的次数 */
	struct tnode *left;		/* 左子节点 */
	struct tnode *right;	/* 右子节点 */
};

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
