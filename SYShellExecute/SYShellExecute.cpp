// SYShellExecute.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h> 
#include <windows.h>
#include <shellapi.h>
#include <string>
#include <windows.h>

std::wstring getexepath()
{
	WCHAR path[ MAX_PATH ];
	GetModuleFileName( NULL, path, MAX_PATH );
	for (size_t i = wcslen(path); path[i] !='\\'; i--) path[i] = NULL;
	return std::wstring(path);
}

void ShellExecuteWait(const wchar_t *path, const wchar_t *lpDirectory)
{
	ShellExecute(NULL, L"open", path, NULL, lpDirectory, SW_SHOW);  

	Sleep(1000);
	while (true)
	{
		HWND handle = FindWindowW(L"ConsoleWindowClass", path);
		if (handle==NULL) {
			break;
		}
		Sleep(1000);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{

	std::wstring path = getexepath() + L"Test5sPause.exe";
	printf("ShellExecute:%S\n", path.c_str());

	ShellExecuteWait(path.c_str(), getexepath().c_str());
	
	printf("ShellExecute:Did close\n");


	system("PAUSE");
	return 0;
}

