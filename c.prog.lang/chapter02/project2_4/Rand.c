/* Rand.c 随即函数发生器 */ 

#include <stdio.h>
#include <time.h> 

unsigned long int next = 1;		/* 种子 */
 
int rand(void);
void srand(unsigned int seed); 

int main(int argc, char *argv[])
{
	int i; 
	int num; 
	unsigned int tm; 
	
	printf("调用rand()10次(种子为1)\n");
	for (i = 1; i <= 10; ++i)
	{
		num = rand();
		printf("%d ", num);
	}
	
	tm = (unsigned)time(0);		/* 取当前秒数 */ 
	srand(tm);					/* 设置种子 */ 
	printf("\n调用rand()10次(种子为%u)\n", tm);
	for (i = 1; i <= 10; ++i)
	{
		num = rand();
		printf("%d ", num);
	}
	
	system("PAUSE");	
	return 0;
}

/* rand函数：返回取值在0~32767之间的伪随机数 */ 
int rand(void) 
{
	next = next * 1103515245 + 12345;
	return (unsigned int)(next / 65536) % 32768;
}

/* srand函数：为rand()函数设置种子数 */
void srand(unsigned int seed)
{
	next = seed;
} 
