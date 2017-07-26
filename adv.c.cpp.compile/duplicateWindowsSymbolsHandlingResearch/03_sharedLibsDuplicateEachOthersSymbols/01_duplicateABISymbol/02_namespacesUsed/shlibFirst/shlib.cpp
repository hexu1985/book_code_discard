#include <stdio.h>

namespace shlibfirst
{

int shlib_function(void)
{
	printf("shlibFirst: %s\n", __FUNCTION__);
    return 0;
}

int shlibfirst_function(void)
{
	printf("%s\n", __FUNCTION__);
	return 0;
}

}; // namespace shlibfirst
