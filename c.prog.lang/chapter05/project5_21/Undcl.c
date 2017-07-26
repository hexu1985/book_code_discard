/* Dcl.c */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define		MAXTOKEN	100

enum {NAME, PARENS, BRACKETS};

int gettoken(void);

int tokentype;				/* 最后一个记号的类型 */
char token[MAXTOKEN]; 		/* 最后一个记号字符串 */
char name[MAXTOKEN];		/* 标示符名 */
char datatype[MAXTOKEN];	/* 数据类型为char、int等 */
char out[1000];				/* 输出串 */ 

/* undcl函数：将文字转换为声明 */ 
int main(int argc, char *argv[])	 
{
	int type;
	char temp[MAXTOKEN];
	
	while (gettoken() != EOF) {
		strcpy(out, token);
		while ((type = gettoken()) != '\n') 
			if (type == PARENS || type == BRACKETS) 
				strcat(out, token);
			else if (type == '*') {
				sprintf(temp, "(*%s)", out);
				strcpy(out, temp);
			} else if (type == NAME) {
				sprintf(temp, "%s %s", token, out);
				strcpy(out, temp);
			} else
				printf("invalid input at %s\n", token);
		printf("%s\n", out);
	}
	system("PAUSE");	
	return 0;
}

int gettoken(void)		/* 返回下一个标记 */
{
	int c, getch(void);
	void ungetch(int);
	char *p = token;
	
	while ((c = getch()) == ' ' || c == '\t') 
		;
	if (c == '(') {
		if ((c = getch()) == ')') {
			strcpy(token, "()");
			return tokentype = PARENS;
		} else {
			ungetch(c);
			return tokentype = '(';
		}
	} else if (c == '[') {
		for (*p++ = c; (*p++ = getch()) != ']'; ) 
			;
		*p = '\0';
		return tokentype = BRACKETS;
	} else if (isalpha(c)) {
		for (*p++ = c; isalnum(c = getch()); ) 
			*p++ = c;
		*p = '\0';
		ungetch(c);
		return tokentype = NAME;
	} else
		return tokentype = c;
} 
