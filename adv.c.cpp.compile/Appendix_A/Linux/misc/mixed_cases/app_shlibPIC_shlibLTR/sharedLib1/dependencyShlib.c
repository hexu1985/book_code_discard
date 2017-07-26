#include <stdio.h>
#include "dependencyShlib.h"

int dependency_shlib_function(int x, int y)
{
	printf("%s\n", __FUNCTION__);
	return 0;
}
