/* Qsort.c 快速排序 */
 
#include <stdio.h>

void qsort(int v[], int left, int right);
void swap(int v[], int i, int j);
void printArray(int v[], int left, int right);

int main(int argc, char *argv[])
{
	const int NUM = 100;
	int iArray[NUM], i, n;
	
	for (i = 0; i < NUM; i++)
	{
		n = i / 2;
		if (i % 2 == 0) 
			iArray[i] = 2 * n + 2;
		else 
			iArray[i] = 100 - 2 * n - 1;
	}
	printf("The Array initially is:");
	printArray(iArray, 0, NUM - 1);
	qsort(iArray, 0, NUM - 1);
	printf("\nThe Array after sort is:");
	printArray(iArray, 0, NUM - 1);
	printf("\n");
	 
	system("PAUSE");	
	return 0;
}

/* qsort函数：以递增顺序对v[left] ...v[right]进行排序 */
void qsort(int v[], int left, int right) 
{
	int i, last;
	
	if (left >= right) 		/* 若数组包含的元素数少于两个 */
		return;				/* 则不执行任何操作 */
	swap(v, left, (left + right) / 2);		/* 将划分子集的元素 */
	last = left;						/* 移动到v[0] */ 
	for (i = left + 1; i <= right; i++) 	/* 划分子集 */
		if (v[i] < v[left]) 
			swap(v, ++last, i);
	swap(v, left, last);		/* 恢复划分子集的元素 */
	qsort(v, left, last - 1);
	qsort(v, last + 1, right);
}

/* swap函数：交换v[i]与v[j]的值 */
void swap(int v[], int i, int j) 
{
	int temp;
	
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
} 

/* printArray函数：打印整型数组 */ 
void printArray(int v[], int left, int right)
{
	int i;
	 
	for (i = left; i <= right; i++) 
	{
		if (i % 5 == 0) 
			printf("\n");
		printf("%3i ", v[i]);
	}
	printf("\n");
}
