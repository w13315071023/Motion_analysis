#include "stdafx.h"
#include "MySerialPort.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	lincoln_class::CMySerialPort obj;
	if (false == obj.Open(12, 9600))
	{
		cout << "open SerialPort is failed !" << endl;
	}
	unsigned char val = 0;
	unsigned char rec = 0;
	while (true)
	{
		if (obj.IsOpened())
		{
			//obj.SendData((char*)&val, sizeof(val));
			while (1)
			{
				int test = obj.ReadData((char*)&rec, 1);
				cout << int(rec) << endl;
			}	
		}
		else
		{
			cout << "SerialPort is not opened !" << endl;
		}
	}
	obj.Close();
	return 0;
}

