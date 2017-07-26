/* Dcl.c */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define		MAXTOKEN	100

enum {NAME, PARENS, BRACKETS};

int gettoken(void);
int nexttoken(void);

int tokentype;				/* 最后一个记号的类型 */
char token[MAXTOKEN]; 		/* 最后一个记号字符串 */
char out[1000];				/* 输出串 */ 

/* undcl: convert word description */ 
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
				if ((type = nexttoken()) == PARENS ||
					type == BRACKETS)
					sprintf(temp, "(*%s)", out);
				else
					sprintf(temp, "*%s", out);
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

enum {NO, YES};

int gettoken(void);

/* nexttoken: get the next token and push it back */
int nexttoken(void)
{
	int type;
	extern int prevtoken;
	
	type = gettoken();
	prevtoken = YES;
	return type;
}

