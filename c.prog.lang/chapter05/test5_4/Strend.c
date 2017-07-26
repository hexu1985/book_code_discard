/* Strend.c strend: return 1 if string t occurs at the end of s */

#include <stdio.h>

int strend(char *sour, char *end);

int main(int argc, char *argv[])
{
	char test1[] = "Hello I am hexu!";
	char test2[] = "hexu!";
	char test3[] = "am";
	
	printf("test1 = [%s]\n", test1);
	printf("test2 = [%s]\n", test2);
	printf("test3 = [%s]\n", test3);
	
	printf("test2 %s in the end of test1\n", 
		(strend(test1, test2) == 1 ? "is" : "isn't"));
	printf("test3 %s in the end of test1\n", 
		(strend(test1, test3) == 1 ? "is" : "isn't"));
			
	system("pause");
	return 0;
}	

/* strend: return 1 if string t occurs at the end of s */
int strend(char *s, char *t)
{
	char *bs = s;			/* remember beginning of strs */
	char *bt = t;
	
	for ( ; *s; s++)		/* end of the string s */
		;
	for ( ; *t; t++)		/* end of the string t */
		;
	for ( ; *s == *t; s--, t--)
		if (t == bt || s == bs)
			break;			/* at the beginning of a str */
	if (*s == *t && t== bt && *s != '\0')
		return 1;
	else
		return 0;
}
