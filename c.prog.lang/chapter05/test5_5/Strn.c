/* Strn.c strncpy strncat strncmp */

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
	printf("after \"strncat(s, s1, sizeof s1)\"\ns = [%s]\n", s);
	strncat(s, s2, 3);
	printf("after \"strncat(s, s2, 3)\"\ns = [%s]\n", s);
	
	strncpy(s, "Hello, I am hexu!", sizeof "Hello, I am hexu!");
	printf("Before strncpy\n");
	printf("s = [%s]\n", s);
	printf("s1 = [%s]\n", s1);
	printf("s2 = [%s]\n", s2);
	printf("s3 = [%s]\n", s3);
	
	strncpy(s, s1, 6);
	printf("after \"strncpy(s, s1, 6)\"\ns = [%s]\n", s);
	strncpy(s, s2, sizeof s2);
	printf("after \"strncpy(s, s2, sizeof s2)\"\ns1 = [%s]\n", s);
	strncpy(s, s3, sizeof s3 - sizeof s2);
	printf("after \"strncpy(s, s3, sizeof s3 - sizeof s2)\"\ns1 = [%s]\n", s);
	
	system("PAUSE");	
	return 0;
}

/*  strncat: concatenate n characters of t to the end of s */
void strncat(char *s, char *t, int n)
{
	strncpy(s + strlen(s), t, n);
}

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
