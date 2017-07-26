#ifndef __STATIC_LIB_EXPORTS_H__
#define __STATIC_LIB_EXPORTS_H__

#include <stdio.h>

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

typedef void (*PRINT_STATIC_LIB_MESSAGE)(int nNumber);
void printStaticLibMessage(int nNumber);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __STATIC_LIB_EXPORTS_H__
