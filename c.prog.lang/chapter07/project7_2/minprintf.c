/* minprintf.c */

#include <stdarg.h>

int main()
{
	int i = 20;
	double d = 20.23;
	void minprintf(char *, ...);
	
	printf("%s\ni = %d, d = %f\n", "printf:", i, d);
	minprintf("%s\ni = %d, d = %f\n", "minprintf:", i, d);
	return 0;
}
	
/* minprintf函数：带有可变参数表的简化的printf函数 */
void minprintf(char *fmt, ...)
{
	va_list ap;		/* 依次指向每一个无名参数 */
	char *p, *sval;
	int ival;
	double dval;
	
	va_start(ap, fmt);	/* 将ap指向第一个无名参数 */
	for (p = fmt; *p; p++) {
		if (*p != '%') {
			putchar(*p);
			continue;
		}
		switch (*++p) {
		case 'd':
			ival = va_arg(ap, int);
			printf("%d", ival);
			break;
		case 'f':
			dval = va_arg(ap, double);
			printf("%f", dval);
			break;
		case 's':
			for (sval = va_arg(ap, char *); *sval; sval++)
				putchar(*sval);
			break;
		default:
			putchar(*p);
			break;
		}
	}
	va_end(ap);		/* 结束时的清理工作 */
}
