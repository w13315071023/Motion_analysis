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
		cin >> val;
		cin.get();

		if (obj.IsOpened())
		{
			obj.SendData((char*)&val, sizeof(val));
			while (1)
			{
				int test = obj.ReadData((char*)&rec, 1);
				//cout << test<<endl;
				if (test != 0)
				{
					cout << int(rec) << endl;
					break;
				}

			}
			
		}
		else
		{
			cout << "SerialPort is not opened !" << endl;
		}

		if (val == 404)
		{
			break;
		}
	}
	obj.Close();


	return 0;
}

