/* Getline.c */

#include <stdio.h>

int getline(char *line, int lim);

int main(int argc, char *argv[])
{
	const int LEN = 128;
	char str[LEN];
	int tmp;
	
	while ((tmp = getline(str, LEN)) > 0)
		printf("tmp = %i :%s", tmp, str);
	
	printf("last tmp = %i", tmp);
	
	system("PAUSE");	
	return 0;
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

