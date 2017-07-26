#include <stdio.h>
//#include <Windows.h>
#include <shlwapi.h>

#define DLL_FILENAME L"VersionedDLL.dll"

BOOL extractDLLProductVersion(HMODULE hDll, DLLVERSIONINFO* pDLLVersionInfo)
{
	if(NULL == pDLLVersionInfo)
		return FALSE;

	DLLGETVERSIONPROC pDllGetVersion;
    pDllGetVersion = (DLLGETVERSIONPROC) GetProcAddress(hDll, "DllGetVersion");
    if(NULL == pDllGetVersion)
		return FALSE;

	ZeroMemory(pDLLVersionInfo, sizeof(DLLVERSIONINFO));
	pDLLVersionInfo->cbSize = sizeof(DLLVERSIONINFO);
	HRESULT hr = (*pDllGetVersion)(pDLLVersionInfo);
	if(FAILED(hr))
		return FALSE;

	return TRUE;
}

BOOL versionInfoFromFileVersionInfoString(LPSTR lpstrFileVersionInfo, DLLVERSIONINFO* pDLLVersionInfo)
{
    static WCHAR fileVersion[256];
    LPWSTR lpwstrVersion    = NULL;
	UINT   nVersionLen  = 0;
    DWORD  dwLanguageID = 0;
    BOOL   retVal;

	if(NULL == pDLLVersionInfo)
		return FALSE;

    wsprintf(fileVersion, L"\\VarFileInfo\\Translation");
    retVal = VerQueryValue ( lpstrFileVersionInfo,  
                             fileVersion, (LPVOID*)&lpwstrVersion, (UINT *)&nVersionLen);
    if(retVal && (4 == nVersionLen))
    {
		memcpy(&dwLanguageID, lpwstrVersion, nVersionLen);
        wsprintf(fileVersion, L"\\StringFileInfo\\%02X%02X%02X%02X\\FileVersion",
                (dwLanguageID & 0xff00)>>8, dwLanguageID & 0xff, (dwLanguageID & 0xff000000)>>24, 
                (dwLanguageID & 0xff0000)>>16);            
    }
    else 
        wsprintf(fileVersion,L"\\StringFileInfo\\%04X04B0\\FileVersion",GetUserDefaultLangID());

    if(FALSE == VerQueryValue (lpstrFileVersionInfo, fileVersion, (LPVOID*)&lpwstrVersion, (UINT *)&nVersionLen))
        return FALSE;

	LPWSTR pwstrSubstring = NULL;
	WCHAR* pContext = NULL;
	pwstrSubstring = wcstok_s(lpwstrVersion, L".", &pContext);
	pDLLVersionInfo->dwMajorVersion = _wtoi(pwstrSubstring);

	pwstrSubstring = wcstok_s(NULL, L".", &pContext);
    pDLLVersionInfo->dwMinorVersion = _wtoi(pwstrSubstring);

	pwstrSubstring = wcstok_s(NULL, L".", &pContext);
	pDLLVersionInfo->dwBuildNumber = _wtoi(pwstrSubstring);
	
	pwstrSubstring = wcstok_s(NULL, L".", &pContext);
	pDLLVersionInfo->dwPlatformID = _wtoi(pwstrSubstring);

	pDLLVersionInfo->cbSize = 5*sizeof(DWORD);
	return TRUE;
}

BOOL extractDLLFileVersion(DLLVERSIONINFO* pDLLVersionInfo)
{
    DWORD dwVersionHandle = 0; 
    DWORD dwVersionInfoSize = GetFileVersionInfoSize (DLL_FILENAME, &dwVersionHandle);
    if(0 == dwVersionInfoSize)
        return FALSE;

    LPSTR lpstrFileVersionInfo = (LPSTR) malloc (dwVersionInfoSize); 
    if (lpstrFileVersionInfo == NULL)
        return FALSE;   // Allocation failed

    BOOL bRetValue = GetFileVersionInfo(DLL_FILENAME, dwVersionHandle, dwVersionInfoSize, lpstrFileVersionInfo);
	if(bRetValue)
	{
		bRetValue = versionInfoFromFileVersionInfoString(lpstrFileVersionInfo, pDLLVersionInfo);
	}

    free (lpstrFileVersionInfo);
    return bRetValue;
}

int main(int argc, char* argv[])
{
	HMODULE hDll = ::LoadLibrary(DLL_FILENAME);
	if(NULL == hDll)
	{
		printf("Failed loading the VersionedDLL.dll\n");
		return -1;
	}

	DLLVERSIONINFO dvi;

	//
	// Querying DLL for its version number
	// 
	memset(&dvi, 0, sizeof(DLLVERSIONINFO));
	if(extractDLLProductVersion(hDll, &dvi))
	{
		printf("DLL Product Version (major, minor, build, platformID) = %d.%d.%d.%d\n", 
		        dvi.dwMajorVersion, dvi.dwMinorVersion, dvi.dwBuildNumber, dvi.dwPlatformID);
	}
	else
		printf("DLL Product Version extraction failed\n");
	FreeLibrary(hDll);
	hDll = NULL;

	//
	// Examining the DLL file ourselves
	//
	memset(&dvi, 0, sizeof(DLLVERSIONINFO));
	if(extractDLLFileVersion(&dvi))
	{
		printf("DLL File Version (major, minor, build, platformID) = %d.%d.%d.%d\n", 
		       dvi.dwMajorVersion, dvi.dwMinorVersion, dvi.dwBuildNumber, dvi.dwPlatformID);
	}
	else
		printf("DLL File Version extraction failed\n");

	FreeLibrary(hDll);

	return 0;
}