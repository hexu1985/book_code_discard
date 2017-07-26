#pragma once

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

int shlib_function(void); // duplicate ABI function
int shlibfirst_function(void);

#ifdef __cplusplus
}
#endif // __cplusplus
