/* closedir.c */
#include <unistd.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "dirent.h"

/* closedir函数：关闭由opendir打开的目录 */
void closedir(DIR *dp)
{
	if(dp) {
		close(dp->fd);
		free(dp);
	}
}
