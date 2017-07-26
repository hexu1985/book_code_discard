/* Dcl.c */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

enum {NAME, PARENS, BRACKETS};
enum {NO, YES};

void dcl(void);
void dirdcl(void);
void errmsg(char *);
int gettoken(void);

extern int tokentype;		/* type of last token */
extern char token[]; 		/* last token string */
extern char name[];			/* identifier name */
extern char out[];			/* Êä³ö´® */ 
extern int prevtoken;

/* dcl: parse a declarator */
void dcl(void)
{
	int ns;
	
	for (ns = 0; gettoken() == '*'; )	/* count *'s */
		ns++;
	dirdcl();
	while (ns-- > 0)
		strcat(out, " *");
}

/* dirdcl: parse a direct declaration */
void dirdcl(void)
{
	int type;
	
	if (tokentype == '(') {		/* (dcl) */ 
		dcl();
		if (tokentype != ')') 
			errmsg("error: missing )\n");
	} else if (tokentype == NAME) 	/* variable name */
		strcpy(name, token);
	else
		errmsg("error: expected name or (dcl)\n");
	while ((type = gettoken()) == PARENS || type == BRACKETS) 
		if (type == PARENS) 
			strcat(out, " ()");
		else {
			strcat(out, " ");
			strcat(out, token);
		}
} 

/* errmsg: print error message and indicate avail. token */
void errmsg(char *msg)
{
	printf("%s", msg);
	prevtoken = YES;
}
