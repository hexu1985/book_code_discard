/* _flushbuf.c */
#include <fcntl.h>
#include <unistd.h>

/* _flushbuf: allocate and flush output buffer */
int _flushbuf(int x, FILE *fp)
{
	unsigned nc;		/* # of chars to flush */
	int bufsize;		/* size of buffer alloc. */
	
	if (fp < _iob || fp >= _iob + OPEN_MAX)
		return EOF;		/* error: invalid pointer */
	if ((fp->flag & (_WRITE | _ERR)) != _WRITE)
		return EOF;
	bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
	if (fp->base == NULL) {		/* no buffer yet */
		if ((fp->base = (char *) malloc(bufsize)) == NULL) {
			fp->flag |= _ERR;
			return EOF;			/* error: return EOF */
		}
	}
	fp->ptr = fp->base;		/* beginning of buffer */
	*fp->ptr++ = (char) x;	/* save current char */
	fp->cnt = bufsize - 1;
	return x;
}
