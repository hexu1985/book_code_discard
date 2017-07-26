/* fsize.c */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>		/* 读写标志 */
#include <sys/types.h>	/* 类型定义 */
#include <sys/stat.h>	/* stat返回的结构 */
#include "dirent.h"

void dirwalk(char *, void (*fcn)(char *));

/* fsize函数：打印文件name的长度 */
void fsize(char *name)
{
	struct stat stbuf;
	
	if (stat(name, &stbuf) == -1) {
		fprintf(stderr, "fsize: can't access %s\n", name);
		return;
	}
	if ((stbuf.st_mode & S_IFDIR))
		dirwalk(name, fsize);
	printf("%8ld %s\n", stbuf.st_size, name);
}
