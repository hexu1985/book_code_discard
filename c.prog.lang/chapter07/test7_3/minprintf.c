/* minprintf.c */

#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

#define		LOCALFMT	100

int main()
{
	int a = 12;
	double b = 12.0;
	char *s = "hello, world";
	
	printf(":%%s:\n");
	minprintf(":%s:\n", s);
	printf(":%%10s:\n");
	minprintf(":%10s:\n", s);
	printf(":%%.10s:\n");
	minprintf(":%.10s:\n", s);
	printf(":%%-10s:\n");
	minprintf(":%-10s:\n", s);
	printf(":%%.15s:\n");
	minprintf(":%.15s:\n", s);
	printf(":%%-15s:\n");
	minprintf(":%-15s:\n", s);
	printf(":%%15.10s:\n");
	minprintf(":%15.10s:\n", s);
	printf(":%%-15.10s:\n");
	minprintf(":%-15.10s:\n", s);
	printf("%%d\n");
	minprintf("%d\n", a);
	printf("%%x\n");
	minprintf("%x\n", a);
	printf("%%o\n");
	minprintf("%o\n", a);
	printf("%%f\n");
	minprintf("%f\n", b);
	return 0;
}	
	
/* minprintf: minimal printf with variable argument list */
void minprintf(char *fmt, ...)
{
	va_list ap;			/* points to each unnamed arg */
	char *p, *sval;
	char localfmt[LOCALFMT];
	int i, ival;
	unsigned uval;
	double dval;
	
	
	va_start(ap, fmt);	/* make ap point to 1st unnamed arg */
	for (p = fmt; *p; p++) {
		if (*p != '%') {
			putchar(*p);
			continue;
		}
		i = 0;
		localfmt[i++] = '%';		/* start local fmt */
		while (*(p+1) && !isalpha(*(p+1)))
			localfmt[i++] = *++p;	/* collect chars */
		localfmt[i++] = *(p+1);		/* format letter */
		localfmt[i] = '\0';
		switch(*++p) {				/* format letter */
		case 'd':
		case 'i':
			ival = va_arg(ap, int);
			printf(localfmt, ival);
			break;
		case 'x':
		case 'X':
		case 'u':
		case 'o':
			uval = va_arg(ap, unsigned);
			printf(localfmt, uval);
			break;
		case 'f':
			dval = va_arg(ap, double);
			printf(localfmt, dval);
			break;
		case 's':
			sval = va_arg(ap, char *);
			printf(localfmt, sval);
			break;
		default:
			printf(localfmt);
			break;
		}
	}
	va_end(ap);			/* clean up */
}
