#include "stdafx.h"
#include "MySerialPort.h"
#include "getport.h"
#include <iostream>
using namespace std;
using namespace lincoln_class;

int _tmain(int argc, _TCHAR* argv[])
{
	CMySerialPort obj;
	unsigned int msg=0;
	unsigned int prev_msg = 0;
	int com_num = get_port_num();
	cout << com_num << endl;
	if (com_num == 0)
		cout << "no valid usb serial port!" << endl;
	else
	{
		obj.Open(com_num, 9600);
		while (1)
		{
			int recv_flag = obj.ReadData((unsigned int*)&msg, 4); //the num of read byte
			if (recv_flag != 0)
			{
				if (msg != prev_msg)
				{
					prev_msg = msg;
					unsigned int tran_msg = msg;
					if (tran_msg == 1)
						cout << tran_msg << " :no ball!" << endl;
					else if (tran_msg == 2)
						cout << tran_msg << " :has ball no hit!" << endl;
					else if (tran_msg == 3)
						cout << tran_msg << " :has ball hit valid!" << endl;
					else if (tran_msg == 4)
						cout << tran_msg << " :has ball hit invalid!" << endl;
					else
						cout << "error!" << endl;
				}
			}
		}
	}
	return 0;
}

