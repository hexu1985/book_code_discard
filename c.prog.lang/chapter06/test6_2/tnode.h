/* tnode.h */

struct tnode {				/* the tree node */
	char *word;				/* points to the next */
	int match;				/* match found */
	struct tnode *left;		/* left child */
	struct tnode *right;	/* right child */
};

#define		YES		1
#define		NO		0

struct tnode *addtreex(struct tnode *, char *, int, int *);
void treexprint(struct tnode *);
