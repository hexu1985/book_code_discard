/* opendir.c */
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "dirent.h"

/* opendir函数：打开目录供函数readdir使用 */
DIR *opendir(char *dirname)
{
	int fd;
	struct stat stbuf;
	DIR *dp;
	
	if ((fd = open(dirname, O_RDONLY, 0)) == -1 ||
		fstat(fd, &stbuf) == -1 ||
		(stbuf.st_mode & S_IFMT) != S_IFDIR ||
		(dp = (DIR *) malloc(sizeof(DIR))) == NULL)
		return NULL;
	dp->fd = fd;
	return dp;
}
