/* sortlist.c */

#include "tnode.h"

extern struct tnode *list[];		
extern int ntn;						

/* sortlist: sort list of pointers to tree nodes */
void sortlist()
{
	int gap, i, j;
	struct tnode *temp;
	for (gap = ntn/2; gap > 0; gap /= 2)
		for (i = gap; i < ntn; i++)
			for (j = i-gap; i >= 0; i -= gap) {
				if ((list[j]->count) >= (list[j+gap]->count))
					break;
				temp =  list[j];
				list[j] = list[j+gap];
				list[j+gap] = temp;
			}
}