#include <cstring>
#include <cstdlib>

int ival = 1024;
void *pv;
int *pi = &ival;
const char *pc = "a casting call";
void mumble()
{
	pv = pi; // ok: pv 指向 ival
	pi = pv; // 错误: 没有标准的转换
	char *pstr = new char[ strlen( pc )+1 ];
	char *pstr2 = malloc(strlen(pc) + 1);	// 错误: 没有标准的转换
	strcpy( pstr, pc );
}