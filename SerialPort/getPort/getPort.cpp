// getport.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "EnumSerial.h"


int _tmain(int argc, _TCHAR* argv[])
{
	int m_nSerialPortNum(0);// 串口计数 
	CString          strSerialList[256];  // 临时定义 256 个字符串组 
	CArray<SSerInfo, SSerInfo&> asi;
	EnumSerialPorts(asi,TRUE);// 参数为 TRUE 时枚举当前可以打开的串口， 
	// 否则枚举所有串口 
	m_nSerialPortNum = asi.GetSize();
	for (int i = 0; i<asi.GetSize(); i++)
	{
		CString str = asi[i].strFriendlyName;
		printf("serialinfo:%s\n",str);
	}
	return 0;
}


