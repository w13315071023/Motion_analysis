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
	while (true)
	{
		cin >> val;
		cin.get();

		if (obj.IsOpened())
		{
			obj.SendData((char*)&val, sizeof(val));
		}
		else
		{
			cout << "SerialPort is not opened !" << endl;
		}

		if (val == 726)
		{
			break;
		}
	}
	obj.Close();


	return 0;
}

