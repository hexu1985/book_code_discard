#include <stdio.h>

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

int shlib_function(void)
{
	printf("shlibSecond: %s\n", __FUNCTION__);
    return 0;
}

int shlibsecond_function(void)
{
	printf("%s\n", __FUNCTION__);
	return 0;
}

int shlibsecond_another_function(void)
{
	printf("%s\n", __FUNCTION__);
	shlib_function();
	return 0;
}

#ifdef __cplusplus
}
#endif // __cplusplus