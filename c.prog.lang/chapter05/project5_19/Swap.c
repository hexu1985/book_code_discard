/* Swap.c */
 
#include <stdlib.h>

void swap(void *v[], int i, int j) 
{
	void *temp;
	
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
