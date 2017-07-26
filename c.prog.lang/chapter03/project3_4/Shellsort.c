/* Shellsort.c Shell排序 */
 
#include <stdio.h>
 
void shellsort(int forsort[], int len);
void printIntArray(int intArr[], int len);

int main(int argc, char *argv[])
{
	const int LEN = 100;
	int iArray[LEN];
	int i, n;
	
	for (i = 0; i < LEN; i++)
	{
		n = i / 2; 
		if (i % 2 == 0)
			iArray[i] = 2 * n + 1;
		else 
			iArray[i] = 100 - 2 * n;
	}
	printf("Initial array is:");
	printIntArray(iArray, LEN); 
	shellsort(iArray, LEN);
	printf("After shellsort array is:");
	printIntArray(iArray, LEN); 
	
	system("PAUSE");	
	return 0;
}

/* shellsort函数：按递增顺序对v[0]...v[n-1]进行排序 */ 
void shellsort(int v[], int n)
{
	int gap, i, j, temp;
	
	for (gap = n / 2; gap > 0; gap /= 2)
		for (i = gap; i < n; i++)
			for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap)
			{
				temp = v[j];
				v[j] = v[j + gap];
				v[j + gap] = temp;
			}
}

void printIntArray(int v[], int n)
{
	int i;
	
	for (i = 0; i < n; i++) 
	{
		if (i % 10 == 0)
			printf("\n");
		printf("%3d ", v[i]);
	}
	printf("\n");
}
