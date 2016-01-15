// getport.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include "EnumSerial.h"
#include <iostream>
#include <atlconv.h>
#include <string>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	USES_CONVERSION;
	int com_num = 0;
	int m_nSerialPortNum(0);// 串口计数 
	CString          strSerialList[256];  // 临时定义 256 个字符串组 
	CArray<SSerInfo, SSerInfo&> asi;
	EnumSerialPorts(asi,TRUE);// TRUE 时枚举当前可以打开的串口， FALSE 枚举所有串口	

	m_nSerialPortNum = asi.GetSize();
	for (int i = 0; i<asi.GetSize(); i++)
	{
		CString str = asi[i].strFriendlyName;
		string com_port_str = W2A(str);
		if (!strncmp(com_port_str.c_str(), "USB Serial", 10))
		{
			CString str1 = str;
			int npos_head = str1.Find(L"COM");  //not find return -1 else return 0
			if (npos_head > -1)
			{
				npos_head = npos_head + 3;
			}
			int npos_end = str1.Find(')');
			if (npos_end > -1)
			{
			}
			CString str2 = str1.Mid(npos_head, npos_end - npos_head);
			com_num = atoi(W2A(str2));
			break;
		}	
	}
	cout << com_num << endl;
	return com_num;	
}


