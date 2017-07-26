#include <stdio.h>

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

int shlib_function(void)
{
	printf("sharedLib: %s\n", __FUNCTION__);
    return 0;
}

int shared_static_duplicate_function(int x)
{
	printf("sharedLib: %s\n", __FUNCTION__);
	return 0;
}

#ifdef __cplusplus
}
#endif // __cplusplus