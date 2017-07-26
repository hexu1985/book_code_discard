#include <stdio.h>

int binsearch(int x, int v[], int n);

int main(int argc, char *argv[])
{
	const int LEN = 100; 
	int iArray[LEN];
	int iSearch, i, iPos; 
	
	for (i = 1; i <= 100; ++i)
		iArray[i] = i * 10;
	
	printf("输入你要查找的数: ");
	scanf("%d", &iSearch);
	iPos = binsearch(iSearch, iArray, LEN);
	if (iPos == -1)
		printf("Sorry, 没有你想要的.\n");
	else
		printf("Oh, 在第%d的位置找到%d.\n", iPos, iSearch);		 
	
	system("PAUSE");	
	return 0;
}

/* binsearch函数：在v[0]<=v[1]<=v[2]<=...<=v[n-1]中查找x */ 
int binsearch(int x, int v[], int n)
{
	int low, high, mid;
	
	low = 0;
	high = n - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else	/* 找到了匹配的值 */
			return mid;
	} 
	return -1;	/* 没有匹配的值 */
} 
