/* fflush.c */
#include <unistd.h>
#include <fcntl.h>

int _flushbuf(int x, FILE *fp);

/* fflush: flush buffer associated with file fp */
int fflush(FILE *fp)
{
	int rc = 0;
	
	if (fp < _iob || fp >= _iob + OPEN_MAX)
		return EOF;				/* error: invalid pointer */
	if (fp->flag & _WRITE)
		rc = _flushbuf(0, fp);
	fp->ptr = fp->base;
	fp->cnt = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
	return rc;
}