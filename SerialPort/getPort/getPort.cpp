// getport.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "EnumSerial.h"


int _tmain(int argc, _TCHAR* argv[])
{
	int m_nSerialPortNum(0);// ���ڼ��� 
	CString          strSerialList[256];  // ��ʱ���� 256 ���ַ����� 
	CArray<SSerInfo, SSerInfo&> asi;
	EnumSerialPorts(asi,TRUE);// ����Ϊ TRUE ʱö�ٵ�ǰ���Դ򿪵Ĵ��ڣ� 
	// ����ö�����д��� 
	m_nSerialPortNum = asi.GetSize();
	for (int i = 0; i<asi.GetSize(); i++)
	{
		CString str = asi[i].strFriendlyName;
		printf("serialinfo:%s\n",str);
	}
	return 0;
}


