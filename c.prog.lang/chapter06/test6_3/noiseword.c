/* noiseword.c */

#include <string.h>

/* noiseword: identify word as a noise word */
int noiseword(char *w)
{
	static char *nw[] = {
		"a",
		"an",
		"and",
		"are",
		"in",
		"is",
		"of",
		"or",
		"that",
		"the",
		"this",
		"to"
	};
	int cond, mid;
	int low = 0;
	int high = sizeof(nw) / sizeof(char *) - 1;
	
	while (low <= high) {
		mid = (low + high) / 2;
		if ((cond = strcmp(w, nw[mid])) < 0)
			high = mid - 1;
		else if (cond > 0)
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}