// getPort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <iostream>
#pragma warning( disable : 4996 )

int EnumAllComm(TCHAR *buf)
{
	HKEY hkey;
	int result;
	int i = 0;
	*buf = 0;

	result = RegOpenKeyEx(HKEY_LOCAL_MACHINE,
		_T("Hardware\\DeviceMap\\SerialComm"),
		NULL,
		KEY_READ,
		&hkey);

	if (ERROR_SUCCESS == result)   //   打开串口注册表   
	{
		TCHAR portName[0x100], commName[0x100]; //commName就是串口名字
		DWORD dwLong, dwSize;

		do
		{
			dwSize = sizeof(portName) / sizeof(TCHAR);
			dwLong = dwSize;
			result = RegEnumValue(hkey, i, portName, &dwLong, NULL, NULL, (LPBYTE)commName, &dwSize);
			if (ERROR_NO_MORE_ITEMS == result)
			{
				break;   
			}
			_tcscpy(buf, commName);
			buf += (_tcslen(buf) + 1);
			i++;
		} while (1);

		RegCloseKey(hkey);
	}

	*buf = 0;

	return i;
}


int _tmain(int argc, _TCHAR* argv[])
{
	TCHAR buf[10000];
	int port = EnumAllComm(buf);	
	int iLen = 2 * wcslen(buf);//CString,TCHAR汉字算一个字符，因此不用普通计算长度   
	char* chRtn = new char[iLen + 1];
	wcstombs(chRtn, buf, iLen + 1);//转换成功返回为非负值  
	std::cout << chRtn;
	return 0;
}

