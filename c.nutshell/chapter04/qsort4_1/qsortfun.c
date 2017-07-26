/* qsortfun.c:  快速排序 */

#include <stdlib.h>
#include <stdio.h>

#define ARR_LEN 20

/*
 * 此函数用来比较两个浮点数元素
 * 此函数作为sqort()的回调(call-back)函数
 * 
 * 返回值:  -1，表示第一个元素小于第二个元素；
			 0，表示两者相等；
			 1，表示第一个元素大于第二个元素。
 */
int floatcmp( const void* p1, const void* p2 )
{
	float x = *(float*)p1;
	float y = *(float*)p2;

	return (x < y) ? -1 : ((x ==y) ? 0 : 1);
}


/*
 * main()函数对一个float数组进行排序
 */
int main()
{
	/* 动态地分配数组空间 */
	float* pNumbers = malloc( ARR_LEN * sizeof(float) );

	/* 初始化数组元素 */
	float* pTmp = pNumbers;
	float tmp = 25.5;
	int i;
	for (i = 0; i < ARR_LEN / 2; i++) {
		*pTmp = tmp - 2 * i;
		pTmp += 2;
	}

	pTmp = pNumbers + 1;
	for (i = 0; i < ARR_LEN / 2; i++) {
		*pTmp = 2 * i;
		pTmp += 2;
	}

	/* 打印数组元素 */
	pTmp = pNumbers;
	puts("初始化后的字符串");
	for (i = 0; i < ARR_LEN; i++) {
		printf("%4.2f\t", *pTmp);
		pTmp++;
		if ((i + 1) % 5 == 0)
			printf("\n");
	}

	/* 数组排序 */
	/* qsort函数
	 * 对一个数组进行排序
	 * 以“递增的次序”对数组进行排序
	 * 从array的地址开始，使用快速排序算法
	 * 此数组具有n个元素，每个元素的空间大小为element_size
	 * 第四个参数(compare)指向一个“比较函数”，进行两个元素的比较
	 * 被比较的两个元素的地址，会以指针参数的方式传入该比较函数中
	 * 通常该比较函数必须由程序元素自行定义。它必须返回一个
	   值，小于0、等于0，或大于0，分别表示第一个元素小于、等
	   于，或大于第二个元素
	 * void qsort( void *array, size_t n, size_t element_size, 
				   int ( *compare )(const void *, const void *) );
	 */
	qsort( pNumbers, ARR_LEN, sizeof(float), floatcmp );

	/* 打印数组元素 */
	pTmp = pNumbers;
	puts("\nquick排序后的字符串");
	for (i = 0; i < ARR_LEN; i++) {
		printf("%4.2f\t", *pTmp);
		pTmp++;
		if ((i + 1) % 5 == 0)
			printf("\n");
	}

	printf("\n");
	return 0;
}
