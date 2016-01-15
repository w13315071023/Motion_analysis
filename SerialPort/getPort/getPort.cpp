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
	int m_nSerialPortNum(0);// ���ڼ��� 
	CString          strSerialList[256];  // ��ʱ���� 256 ���ַ����� 
	CArray<SSerInfo, SSerInfo&> asi;
	EnumSerialPorts(asi,TRUE);// TRUE ʱö�ٵ�ǰ���Դ򿪵Ĵ��ڣ� FALSE ö�����д���	

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


