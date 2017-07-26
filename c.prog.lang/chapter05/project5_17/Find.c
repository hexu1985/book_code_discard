/* Find.c */
 
#include <stdio.h>
#include <string.h>

#define MAXLINE	1000

int getline(char *line, int max);

/* find函数：打印与第一个参数指定的模式匹配的行 */ 
int main(int argc, char *argv[])
{
	char line[MAXLINE];
	int found = 0;
	 
	if (argc != 2)
		printf("Usage: find pattern\n");
	else
		while (getline(line, MAXLINE) > 0)
			if (strstr(line, argv[1]) != NULL) 
			{
				printf("%s", line);
				found++;
			}

		
	system("PAUSE");	
	return found;
}

int getline(char *s, int lim) 
{
	int c;
	char *t = s; 
	
	for ( ; --lim > 0 && (c = getchar()) != EOF && c != '\n'; ) 
		*s++ = c;
	if (c == '\n') 
		*s++ = c;
	*s = '\0';
	return s - t;
} 
