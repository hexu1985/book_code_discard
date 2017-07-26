#ifndef __SHARED_LIB_EXPORTS_H__
#define __SHARED_LIB_EXPORTS_H__

#include <stdio.h>

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

typedef void (*PRINT_MESSAGE)(void);
void printMessage(void);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __SHARED_LIB_EXPORTS_H__
