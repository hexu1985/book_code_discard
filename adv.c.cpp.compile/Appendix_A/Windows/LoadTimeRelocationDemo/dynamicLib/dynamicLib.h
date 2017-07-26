// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the DYNAMICLIB_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// DYNAMICLIB_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef DYNAMICLIB_EXPORTS
#define DYNAMICLIB_API __declspec(dllexport)
#else
#define DYNAMICLIB_API __declspec(dllimport)
#endif

// Variables intended for export


// Functions intended for export (ABI functions)
#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

#ifdef DYNAMICLIB_EXPORTS
DYNAMICLIB_API int shlibNonStaticAccessedAsExternVariable  = 0;
#else
extern int shlibNonStaticAccessedAsExternVariable  = 0;
#endif 

DYNAMICLIB_API int shlib_abi_initialize(int x, int y);
DYNAMICLIB_API int shlib_abi_uninitialize(void);
DYNAMICLIB_API int shlib_abi_reinitialize(int x, int y);
#ifdef __cplusplus
}
#endif __cplusplus