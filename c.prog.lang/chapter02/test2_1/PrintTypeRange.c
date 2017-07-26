/* PrintTypeRange.c 确定分别由signed及unsigned限定的char、short、int及long类型
					变量的取值范围。采用打印标准头文件中的相应值以及直接计算
					两种方式实现 */
					 
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void printTypeRange1(void);
void printTypeRange2(void);

/* determine ranges of types */
int main(int argc, char *argv[])
{
	printf("Determine ranges of types by limits.h\n");
	printTypeRange1();
	printf("Determine ranges of types by calculate\n");
	printTypeRange2();
	 
	system("PAUSE");	
	return 0;
}

/* 确定各类型变量的取值范围，通过采用打印标准头文件中的相应值 */ 
void printTypeRange1(void)
{
	/* signed types */
	printf("signed char min  = %d\n", SCHAR_MIN);
	printf("signed char max  = %d\n", SCHAR_MAX);
	printf("signed short min = %d\n", SHRT_MIN);
	printf("signed short max = %d\n", SHRT_MAX);
	printf("signed int min   = %d\n", INT_MIN);
	printf("signed int max   = %d\n", INT_MAX);
	printf("signed long min  = %ld\n", LONG_MIN);
	printf("signed long max  = %ld\n", LONG_MAX);
	/* unsigned types */
	printf("unsigned char max  = %u\n", UCHAR_MAX);
	printf("unsigned short max = %u\n", USHRT_MAX);
	printf("unsigned int max   = %u\n", UINT_MAX);
	printf("unsigned long max  = %lu\n", ULONG_MAX);
}

/* 确定各类型变量的取值范围，通过计算来确定相应值 */ 
void printTypeRange2(void)
{
	 /* signed types */
	printf("signed char min  = %d\n", 
			(char)(((unsigned char)~0 >> 1) + 1));
	printf("signed char max  = %d\n", 
			(char)((unsigned char)~0 >> 1));
	printf("signed short min = %d\n", 
			(short)(((unsigned short)~0 >> 1) + 1));
	printf("signed short max = %d\n", 
			(short)((unsigned short)~0 >> 1));
	printf("signed int min   = %d\n", 
			(int)(((unsigned int)~0 >> 1) + 1));
	printf("signed int max   = %d\n", 
			(int)((unsigned int)~0 >> 1));
	printf("signed long min  = %ld\n", 
			(long)(((unsigned long)~0 >> 1) + 1));
	printf("signed long max  = %ld\n", 
			(long)((unsigned long)~0 >> 1));
	/* unsigned types */
	printf("unsigned char max  = %u\n", (unsigned char)~0);
	printf("unsigned short max = %u\n", (unsigned short)~0);
	printf("unsigned int max   = %u\n", (unsigned int)~0);
	printf("unsigned long max  = %lu\n", (unsigned long)~0);
}
