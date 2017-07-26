/* Numcmp.c */

#include <stdlib.h>
#include <string.h>

#define		MAXSTR		100
 
/* numcmp函数：按数值顺序比较字符串s1和s2 */
int numcmp(char *s1, char *s2)
{
	double v1, v2;
	char str[MAXSTR];
	
	strncpy(str, s1, MAXSTR);
	v1 = atof(str);
	strncpy(str, s2, MAXSTR);
	v2 = atof(str);
	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else
		return 0;
}
