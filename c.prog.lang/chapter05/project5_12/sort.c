/* Sort.c */

#include <stdio.h>
#include <string.h>

#define MAXLINES	5000	/* 进行排序的最大文本行数 */

char *lineptr[MAXLINES]; 	/* 指向文本行的指针数组 */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right); 

/* 对输入的文本行进行排序 */ 
int main(int argc, char *argv[])
{
	int nlines;		/* 读取的输入行数目 */
	
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) 
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
