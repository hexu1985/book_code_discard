#include <stdio.h>
#include <Windows.h>

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus
typedef HRESULT (*PDLL_REGISTER_SERVER)(void);
typedef HRESULT (*PDLL_UNREGISTER_SERVER)(void);
#ifdef __cplusplus
}
#endif // __cplusplus

enum
{
	CMD_LINE_ARG_INDEX_EXECUTABLE_NAME = 0,
	CMD_LINE_ARG_INDEX_INPUT_DLL,
	CMD_LINE_ARG_INDEX_REGISTER_OR_UNREGISTER,
	NUMBER_OF_SUPPORTED_CMD_LINE_ARGUMENTS
} CMD_LINE_ARG_INDEX;

int main(int argc, char* argv[])
{
	HINSTANCE dllHandle = ::LoadLibraryA(argv[CMD_LINE_ARG_INDEX_INPUT_DLL]);
	if(NULL == dllHandle)
	{
		printf("Failed loading %s\n", argv[CMD_LINE_ARG_INDEX_INPUT_DLL]);
		return -1;
	}

	if(NUMBER_OF_SUPPORTED_CMD_LINE_ARGUMENTS > argc)
	{
		PDLL_REGISTER_SERVER pDllRegisterServer = 
				(PDLL_REGISTER_SERVER)GetProcAddress(dllHandle, "DllRegisterServer");
		if(NULL == pDllRegisterServer)
		{
			printf("Failed finding the symbol \"DllRegisterServer\"");
			::FreeLibrary(dllHandle);
			dllHandle = NULL;
			return -1;
		}
		pDllRegisterServer();
	}
	else
	{
		PDLL_UNREGISTER_SERVER pDllUnregisterServer = 
				(PDLL_UNREGISTER_SERVER)GetProcAddress(dllHandle, "DllUnregisterServer");
		if(NULL == pDllUnregisterServer)
		{
			printf("Failed finding the symbol \"DllUnregisterServer\"");
			::FreeLibrary(dllHandle);
			dllHandle = NULL;
			return -1;
		}

		pDllUnregisterServer();
	}

	::FreeLibrary(dllHandle);
	dllHandle = NULL;
	return 0;
}