/* dirent.h */
#define	NAME_MAX	14	/* 最长文件名；由具体的系统决定 */

typedef struct {	/* 可移植的目录项 */
	long ino;		/* i节点编号 */
	char name[NAME_MAX+1];	/* 文件名加结束符'\0' */
} Dirent;

typedef struct {	/* 最小的DIR: 无缓冲等特性 */
	int fd;			/* 目录的文件描述符 */
	Dirent d;		/* 目录项 */
} DIR;

