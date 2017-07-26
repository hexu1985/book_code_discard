
#include <stdio.h>

static void test()
{
	printf("static function of %s() in %s\n", __func__, __FILE__);
}

void call_test() {
	test();
}