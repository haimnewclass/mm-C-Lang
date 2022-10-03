
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)
#include "mm_c_Utilities.h"

int main_6_2_2_()
{
	//PrintNum(23);
	//PrintNum(34);
}

#ifdef INI
LPCTSTR path = L"C:\\Users\\ASI\\source\\repos\\mm-C-Lang\\mm-C-Lang\\mm-C-Lang.ini";
//LPCTSTR path = "\\mm-C-Lang.ini";
TCHAR protocolChar[32];
int a = GetPrivateProfileString(TEXT("Params"), TEXT("a"), TEXT("000"), protocolChar, 32, path);
#endif