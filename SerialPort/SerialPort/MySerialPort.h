#pragma once
#include <windows.h>

namespace lincoln_class
{
	class CMySerialPort
	{
	public:
		CMySerialPort();
		~CMySerialPort();

		BOOL Open(int nPort, int nBaud);
		BOOL Close(void);

		int ReadData(void *, int);
		int SendData(const char *, int);
		int ReadDataWaiting(void);	//��ѯ���������Ƿ���δ��ȡ������

		BOOL IsOpened(void) {
			return (m_bOpened);
		}

	protected:
		BOOL WriteCommByte(unsigned char);	//�ڲ�ʵ�֣��򴮿�д����

		HANDLE m_hIDComDev;
		OVERLAPPED m_OverlappedRead, m_OverlappedWrite;
		BOOL m_bOpened;
	};
}