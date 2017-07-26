/* main.c */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define		MAXTOKEN	100

enum {NAME, PARENS, BRACKETS};

void dcl(void);
void dirdcl(void);
int gettoken(void);

int tokentype;				/* 最后一个记号的类型 */
char token[MAXTOKEN]; 		/* 最后一个记号字符串 */
char name[MAXTOKEN];		/* 标示符名 */
char datatype[MAXTOKEN];	/* 数据类型为char、int等 */
char out[1000];				/* 输出串 */ 

int main(int argc, char *argv[])	/* 将声明转换为文字描述 */ 
{
	while (gettoken() != EOF) {		/* 该行的第一个记号是数据类型 */
		strcpy(datatype, token);
		out[0] = '\0';
		dcl();		/* 分析该行的其余部分 */ 
		if (tokentype != '\n')
			printf("syntax error\n");
		printf("%s:%s %s\n", name, out, datatype);
	}
	system("PAUSE");	
	return 0;
}

