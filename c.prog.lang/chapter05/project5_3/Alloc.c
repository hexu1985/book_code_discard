/* Alloc.c 动态分配内存空间 */
 
#include <stdio.h>

char *alloc(int n);
void afree(char *p);
void showbuf(int beg, int end);
void showstr(char *p, int n);

int main(int argc, char *argv[])
{
	int i, a1, a2, n;
	char *str1, *str2, *str3;
	
	n = 12;
	str1 = alloc(n);
	for (i = 0; i < n; i++) 
		*(str1 + i) = 'a' + i;
	printf("\nstr1 =\n");
	showstr(str1, n);
	
	n = 14;
	str2 = alloc(n); 
	for (i = 0; i < n; i++) 
		*(str2 + i) = 'A' + i;	
	printf("\nstr2 =\n");
	showstr(str2, n);
	
	a1 = 0;
	a2 = 26; 
	printf("\nallocbuf from %d to %d is:\n", a1, a2 - 1);
	showbuf(a1, a2); 
	
	afree(str2);
	n = 6;
	str3 = alloc(n);
	for (i = 0; i < n; i++)
		*(str3 + i) = '0' + i;
	printf("\nstr3 =\n");
	showstr(str3, n);		
	 
	a1 = 0;
	a2 = 26; 
	printf("\nallocbuf from %d to %d is:\n", a1, a2 - 1);
	showbuf(a1, a2);
	
	printf("\n");
	system("PAUSE");	
	return 0;
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

void afree(char *p) 	/* 释放p指向的存储区 */
{
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE) 
		allocp = p;
}

void showbuf(int beg, int end) 	/* 输出缓冲区中[beg,end)中的所有字符，起始位置为0 */ 
{
	char *ptmp;
	int len, i;
	 
	for (ptmp = allocbuf + beg, i = 0, len = end - beg; i < len; i++)
		printf("%c", *(ptmp + i));
}

void showstr(char *p, int n) /* 输出字符串所指的字符开始的n个字符 */
{
	int i;
	
	for (i = 0; i < n; i++)
		printf("%c", *(p + i));
}

 
