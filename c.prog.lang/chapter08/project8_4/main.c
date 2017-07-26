/* main.c */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>		/* 读写标志 */
#include <sys/types.h>	/* 类型定义 */
#include <sys/stat.h>	/* stat返回的结构 */
#include "dirent.h"

void fsize(char *);

/* 打印文件长度 */
int main(int argc, char **argv)
{
	if (argc == 1)		/* 默认为当前目录 */
		fsize(".");
	else
		while (--argc > 0)
			fsize(*++argv);
	return 0;
}
