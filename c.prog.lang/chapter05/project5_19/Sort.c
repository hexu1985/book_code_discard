/* Sort.c */

#include <stdio.h>
#include <string.h>

#define		MAXLINES	5000	/* 待排序的最大行数 */
char *lineptr[MAXLINES];		/* 指向文本行的指针 */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(void *lineptr[], int left, int right,
			int (*comp)(void *, void *));
int numcmp(char *, char *);

/* 对输入的文本行进行排序 */			
int main(int argc, char *argv[])
{
	int nlines;		/* 读入的输入行数 */
	int numeric;	/* 若进行数值排序，则numeric的值为1 */
	
	if (argc > 1 && strcmp(argv[1], "-n") == 0) 
		numeric = 1;
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) 
	{
		qsort((void **)lineptr, 0, nlines-1,
				(int (*)(void *, void *))(numeric ? numcmp : strcmp));
		writelines(lineptr, nlines);
		return 0;
	}
	else
	{
		printf("input too big to sort\n");
		return 1;
	}
}

/* numcmp函数：按数值顺序比较字符串s1和s2 */
int numcmp(char *s1, char *s2)
{
	double v1, v2;
	
	v1 = atof(s1);
	v2 = atof(s2);
	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else
		return 0;
}

#define MAXLEN	1000	/* 每个输入文本行的最大长度 */

int getline(char *, int);
char *alloc(int);

/* readlines函数：读取输入行 */
int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];
	char *alloc(int n);
	
	nlines = 0;
	while ((len = getline(line, MAXLEN)) > 0) 
		if (nlines >= maxlines || (p = alloc(len)) == NULL) 
			return -1;
		else
		{
			line[len-1] = '\0';		/* 删除换行符 */
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}

/* getline: read a line into s, return length */
int getline(char *s, int lim)
{
	int c;
	char *t = s;
	
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		*s++ = c;
	if (c == '\n')
		*s++ = c;
	*s = '\0';
	return s - t;
}

/* writelines函数：写输出行 */
void writelines(char *lineptr[], int nlines) 
{
	int i;
	
	for (i = 0; i < nlines; i++)
		printf("%s\n", lineptr[i]);
}

#define ALLOCSIZE	8192	/* 可用空间大小 */

static char allocbuf[ALLOCSIZE];	/* alloc使用的存储区 */

static char *allocp = allocbuf;		/* 下一个空闲位置 */
 
char *alloc(int n)		/* 返回值指向n个字符的指针 */ 
{
	if (allocbuf + ALLOCSIZE - allocp >= n) 	/* 有足够的空闲空间 */ 
	{
		allocp += n;
		return allocp - n;		/* 分配前的指针p */
	}
	else
		return 0;
}
