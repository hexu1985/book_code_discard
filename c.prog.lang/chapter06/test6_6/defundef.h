/* defundef.h */

#define MAXWORD		100

struct nlist {		/* 链表项 */
	struct nlist *next;		/* 链表中下一项 */
	char *name;				/* 定义的名字 */
	char *defn;				/* 替换文本 */
};

void error(int, char *);
int getch(void);
void getdef(void);
int getword(char *, int);
struct nlist *install(char *, char *);
struct nlist *lookup(char *);
void skipblanks(void);
void undef(char *);
void ungetch(int);
void ungets(char *);
char *strup(char *);
unsigned hash(char *);
	