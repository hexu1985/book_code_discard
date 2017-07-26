/* tnode.h */

struct linklist {			/* linked list of line numbers */
	int lnum;
	struct linklist *ptr;
};

struct tnode {					/* the tree node */
	char *word;					/* points to the text */
	struct linklist *lines;		/* match found */
	struct tnode *left;			/* left child */
	struct tnode *right;		/* right child */
};

struct tnode *addtreex(struct tnode *, char *, int);
void treexprint(struct tnode *);
