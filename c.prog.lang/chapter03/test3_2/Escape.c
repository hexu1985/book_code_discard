/* Escape.c º¯ÊýescapeºÍº¯Êýunescape */
 
#include <stdio.h>

void escape(char dest[], char sour[]);
void unescape(char dest[], char sour[]); 
int gettext(char text[], int limit); 

int main(int argc, char *argv[])
{
	const int MAXLINE = 500;
	char init[MAXLINE];
	char esc[MAXLINE];
	char unesc[MAXLINE]; 
	int n;	
	
	if ((n = gettext(init, MAXLINE)) > 0)
	{
		printf("\ninit:\n%s\n", init);
		escape(esc, init); 
		printf("\nesc:\n%s\n", esc);
		unescape(unesc, esc);
		printf("\nunsec:\n%s\n", unesc);
		
	}
	else
		printf("\nnothing is in initial string\n");
	
	system("PAUSE");	
	return 0;
}

/* escape: expand newline and tab into visible sequences */
/*		   while copying the string t to s */
void escape(char s[], char t[])
{
	int i, j;
	
	for (i = j = 0; t[i] != '\0'; i++)
		switch (t[i])
		{
		case '\n':		/* newline */
			s[j++] = '\\';
			s[j++] = 'n';
			break;
		case '\t':		/* tab */
			s[j++] = '\\';
			s[j++] = 't';
			break;
		default:		/* all other chars */ 
			s[j++] = t[i]; 
			break;
		}
	s[j] = '\0';
} 

/* unescape: convert escape sequences into real characters */
/*			 while copying the string t to s */
void unescape(char s[], char t[]) 
{
	int i, j;
	
#if defined UNESCAPE_ONE 
	for (i = j = 0; t[i] != '\0'; i++)
		if (t[i] != '\\')
			s[j++] = t[i];
		else					/* it is a backslash */ 
			switch (t[++i]) 
			{
			case 'n':			/* real newline */ 
				s[j++] = '\n';
				break;
			case 't':			/* real tab */ 
				s[j++] = '\t';
				break;
			default:			/* all other chars */ 
				s[j++] = '\\';
				s[j++] = t[i];
				break;
			}
	s[j] = '\0';
#else
	for (i = j = 0; t[i] != '\0'; i++)
		switch (t[i])
		{
		case '\\':				/* backslash */ 
			switch (t[++i]) 
			{
			case 'n': 			/* real newline */
				s[j++] = '\n';
				break;
			case 't':			/* real tab */ 
				s[j++] = '\t';
				break;
			default: 			/* all other chars */
				s[j++] = '\\';
				s[j++] = t[i];
				break;
			}
		default:				/* not a backslash */ 
			s[j++] = t[i];
			break;
		}
	s[j] = '\0';
#endif 
}
 
int gettext(char s[], int lim)
{
	int c, i;
	
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF; ++i)
		s[i] = c;
	s[i] = '\0';
	return i; 
} 
