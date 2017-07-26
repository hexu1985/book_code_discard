/* fclose.c */
#include <fcntl.h>
#include <unistd.h>

int fflush(FILE *fp);

/* fclose: close file */
int fclose(FILE *fp)
{
	int rc;			/* return code */
	
	if ((rc = fflush(fp)) != EOF) {		/* anything to flush? */
		free(fp->base);				/* free allocated buffer */
		fp->ptr = NULL;
		fp->cnt = 0;
		fp->base = NULL;
		fp->flag &= ~(READ | WRITE);
	}
	return rc;
}
