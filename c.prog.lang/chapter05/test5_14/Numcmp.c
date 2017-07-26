/* Numcmp.c */

#include <stdlib.h>

/* numcmp函数：按数值顺序比较字符串s1和s2 */
int numcmp(char *s1, char *s2)
{
	double v1, v2;
	
	printf("-----------numcmp\n");
	printf("s1 = [%s]\t", s1);
	printf("s2 = [%s]\t", s2);
	
	v1 = atof(s1);
	v2 = atof(s2);
	
	printf("v1 = [%lf]\t", v1);
	printf("v2 = [%lf]\n", v2);
	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else
		return 0;
}
