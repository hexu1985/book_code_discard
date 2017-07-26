/* Strncat.c */

#include <stdio.h>

int strlen(char *str);
void strncpy(char *dest, char *sour, int num);
void strncat(char *dest, char *sour, int num);

int main(int argc, char *argv[])
{
	const int SIZE = 128;
	char s[SIZE]; 
	char s1[] = "123456789";
	char s2[] = "Bye";
	char s3[] = "Good Bye";
	int i;
	
	for (i = 0; i < SIZE; i++)
		s[i] = '\0';
	
	strncpy(s, "Hello, I am hexu!", sizeof "Hello, I am hexu!");
	printf("Before strncpy\n");
	printf("s = [%s]\n", s);
	printf("s1 = [%s]\n", s1);
	printf("s2 = [%s]\n", s2);
	printf("s3 = [%s]\n", s3);
	
	strncat(s, s1, sizeof s1);
	printf("s = [%s]\n", s);
	strncat(s, s2, 3);
	printf("s = [%s]\n", s);
	
	system("PAUSE");	
	return 0;
}

/*  strncat: concatenate n characters of t to the end of s */
#ifdef STRNCAT_ONE
void strncat(char *s, char *t, int n)
{
	strncpy(s + strlen(s), t, n);
}
#else
void strncat(char *s, char *t, int n)
{
	char *p = s;
	
	while (*p != '\0')
		p++;
	
	while (*t && n-- > 0)
		*p++ = *t++;
	while (--n > 0)
		*p++ = '\0';
}
#endif

/* strncpy: copy n characters from t to s */
void strncpy(char *s, char *t, int n)
{
	while (*t && n-- > 0)
		*s++ = *t++;
	while (n-- > 0)
		*s++ = '\0';
}

/* strlen函数：返回字符串s的长度 */
int strlen(char *s)
{
	char *p = s;
	
	while (*p != '\0') 
		p++;
	return p - s;
} 
	
