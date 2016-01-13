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

	if (ERROR_SUCCESS == result)   //   �򿪴���ע���   
	{
		TCHAR portName[0x100], commName[0x100]; //commName���Ǵ�������
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
	int iLen = 2 * wcslen(buf);//CString,TCHAR������һ���ַ�����˲�����ͨ���㳤��   
	char* chRtn = new char[iLen + 1];
	wcstombs(chRtn, buf, iLen + 1);//ת���ɹ�����Ϊ�Ǹ�ֵ  
	std::cout << chRtn;
	return 0;
}

