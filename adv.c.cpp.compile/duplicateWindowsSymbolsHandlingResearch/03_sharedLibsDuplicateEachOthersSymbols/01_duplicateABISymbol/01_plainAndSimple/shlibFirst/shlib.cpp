#include <stdio.h>

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

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

#ifdef __cplusplus
}
#endif // __cplusplus