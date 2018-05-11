#include "mm_info.h"
#include <windows.h>
#include "log.h"

struct mm_info_s mm_info;
void FindMMVersion()
{
	switch (*(uint8_t*)0x41EDE1)  // just a random address
	{
		case 0xEC:
			mm_info.version = 6;
			mm_info.MainWindow = (HWND*)0x61076C;
			//SPStatKinds = MM6_SPStatKinds;
			break;
		case 0x45:
			mm_info.version = 7;
			mm_info.MainWindow = (HWND*)0x6BE174;
			//SPStatKinds = MM7_SPStatKinds;
			break;
		case 0x53:
			mm_info.version = 8;
			mm_info.MainWindow = (HWND*)0x6F3934;
			//SPStatKinds = MM8_SPStatKinds;
			break;
		default:
			MessageBox(0, "This is not a supported Might and Magic game", "MMExtension Error", MB_ICONERROR);
			ExitProcess(0);
	}
}

BOOL PRIVATE Initialize(HANDLE hModule);
BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
	BOOL hResult = TRUE;    

	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		hResult = Initialize(hModule);
		break;
	case DLL_PROCESS_DETACH:
		hResult = TRUE;//hResult =   Unload();
		break;
	}
	if(!hResult)TerminateProcess(GetCurrentProcess(),-1);//exit(-1);
	return hResult;
}

BOOL PRIVATE Initialize(HANDLE hModule)
{
    FindMMVersion();
	angel::Log.Init("angel.log");
	return TRUE;
}
