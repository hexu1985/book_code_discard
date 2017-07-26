/* Qsort.c */
 
/* qsort函数：以递增顺序对v[left], ..., v[right]进行排序 */
void qsort(void *v[], int left, int right,
			int (*comp)(void *, void *))
{
	int i, last;
	void swap(void *v[], int, int);
	
	if (left >= right) 		/* 如果数组元素个数小于2，则不执行任何操作 */
		return;
	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left+1; i <= right; i++) 
		if ((*comp)(v[i], v[left]) < 0) 
			swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last-1, comp);
	qsort(v, last+1, right, comp);
}

 
 
