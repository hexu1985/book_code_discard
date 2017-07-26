/* syscall.h */
#include <unistd.h>

typedef long Align;		/* 按照long类型的边界对齐 */

union header {		/* 块的头部 */
	struct {
		union header *ptr;		/* 空闲块链表中的下一块 */
		unsigned size;			/* 本块的大小 */
	} s;
	Align x;		/* 强制块的对齐 */
};

typedef union header Header;