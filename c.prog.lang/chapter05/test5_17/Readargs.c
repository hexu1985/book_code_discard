/* Readargs.c */

#include <stdlib.h>

#define		NUMERIC		1		/* numeric sort */
#define		DECR		2		/* sort in decreasing order */
#define		FOLD		4		/* fold upper and lower case */ 
#define		DIR			8		/* directory order */

void error(char *);

/* readargs: read program arguments */
void readargs(int argc, char *argv[])
{
	extern char option;
	extern int pos1, pos2;
	int c;
	
	while (--argc > 0 && (c = (*++argv)[0]) == '-' || c== '+')
	{
		if (c == '-' && !isdigit(*(argv[0]+1))) 
			while (c = *++argv[0])
				switch (c) 
				{
				case 'd':		/* directory order */
					option |= DIR;
					break;				
				case 'f':		/* fold upper and lower cases */
					option |= FOLD;
					break;
				case 'n':		/* numeric sort */
					option |= NUMERIC;
					break;
				case 'r':		/* sort in decreasing order */
					option |= DECR;
					break;
				default:
					printf("sort: illegal option %c\n", c);
					error("Usage: sort -dfnr [+pos1] [-pos2]");
					break;
				}
		else if (c == '-')
			pos2 = atoi(argv[0]+1);
		else if ((pos1 = atoi(argv[0]+1)) < 0)
			error("Usage: sort -dfnr [+pos1] [-pos2]");
	}
	if (argc || pos1 > pos2)
		error("Usage: sort -dfnr [+pos1] [-pos2]");
}

