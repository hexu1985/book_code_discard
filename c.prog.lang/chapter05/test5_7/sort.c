/* Sort.c */

#include <stdio.h>
#include <string.h>

#define MAXLINES	5000	/* 进行排序的最大文本行数 */
#define ALLOCSIZE	8192	/* 可用空间大小 */

static char allocbuf[ALLOCSIZE];	/* alloc使用的存储区 */

char *lineptr[MAXLINES]; 	/* 指向文本行的指针数组 */

int readlines(char *lineptr[], char *linestor, int maxlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right); 

/* 对输入的文本行进行排序 */ 
int main(int argc, char *argv[])
{
	int nlines;		/* 读取的输入行数目 */
	
	if ((nlines = readlines(lineptr, allocbuf, MAXLINES)) >= 0) 
	{
		qsort(lineptr, 0, nlines - 1);
		writelines(lineptr, nlines);
		system("PAUSE");
		return 0;
	}
	else
	{
		printf("error: input too big to sort\n");
		system("PAUSE");
		return 1;
	}
}

#define MAXLEN	1000	/* maximum length of line */
#define MAXSTOR	5000	/* size of available storage space */ 

int getline(char *, int);

/* readlines: read input lines */
int readlines(char *lineptr[], char *linestor, int maxlines)
{
	int len, nlines;
	char line[MAXLEN];
	char *p = linestor; 
	char *linestop = linestor + MAXSTOR; 
	
	nlines = 0;
	while ((len = getline(line, MAXLEN)) > 0) 
		if (nlines >= maxlines || p+len > linestop) 
			return -1;
		else
		{
			line[len-1] = '\0';		/* delete newline */
			strcpy(p, line);
			lineptr[nlines++] = p;
			p += len; 
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
	while (nlines-- >0) 
		printf("%s\n",*lineptr++);
}
 
/* qsort函数：按递增顺序对v[left] ... v[right]进行排序 */
void qsort(char *v[], int left, int right)
{
	int i, last;
	void swap(char *v[], int i, int j);
	
	if (left >= right)		/* 如果数组元素的个数小于2，则返回 */
		return;
	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left+1; i <= right; i++)
		if (strcmp(v[i], v[left]) < 0) 
			swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last-1); 
	qsort(v, last+1, right);
}

/* swap函数：交换v[i]和v[j] */
void swap(char *v[], int i, int j) 
{
	char *temp;
	
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

