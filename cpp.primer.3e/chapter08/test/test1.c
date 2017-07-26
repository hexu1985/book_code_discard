#include <stdio.h>
#include "test.h"

void test()
{
	printf("extern function of %s() in %s\n", __func__, __FILE__);
}