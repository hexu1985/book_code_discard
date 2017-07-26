/* dirwalk.c */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>		/* 读写标志 */
#include <sys/types.h>	/* 类型定义 */
#include <sys/stat.h>	/* stat返回的结构 */
#include "dirent.h"
#define MAX_PATH	1024

/* dirwalk函数：对dir中的所有文件调用函数fcn */
void dirwalk(char *dir, void (*fcn)(char *))
{
	char name[MAX_PATH];
	Dirent *dp;
	DIR *dfd;
	
	if((dfd = opendir(dir)) == NULL) {
		fprintf(stderr, "dirwalk: can't open %s\n", dir);
		return;
	}
	while ((dp = readdir(dfd)) != NULL) {
		if (strcmp(dp->name, ".") == 0 || 
			strcmp(dp->name, "..") == 0)
			continue;		/* 跳过自身和父目录 */
		if (strlen(dir)+strlen(dp->name)+2 > sizeof(name))
			fprintf(stderr, "dirwalk: name %s/%s too long \n",
					dir, dp->name);
		else {
			sprintf(name, "%s/%s", dir, dp->name);
			(*fcn)(name);
		}
	}
	closedir(dfd);
}
