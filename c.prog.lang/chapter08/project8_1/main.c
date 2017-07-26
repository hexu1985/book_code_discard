/* main.c */
#include <unistd.h>
#include <fcntl.h>

#define BUFSIZ	8192

int main()		/* 将输入复制到输出 */
{
	char buf[BUFSIZ];
	int n;
	
	while ((n = read(0, buf, BUFSIZ)) > 0)
		write(1, buf, n);
	return 0;
}
