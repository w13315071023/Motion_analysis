#include "stdafx.h"
#include "MySerialPort.h"
#include <iostream>
using namespace std;
using namespace lincoln_class;

int get_Port_num(CMySerialPort obj)
{
	for (int port_num = 1; port_num <= 200; port_num++)
	{
		if (false == obj.Open(port_num, 9600))
		{
			//cout << "open SerialPort is failed_1 !" << endl;
		}
		else
		{
		  unsigned char hook = 66;
		  unsigned char ack = 0;
		  obj.SendData((char*)&hook, sizeof(hook));
		  Sleep(5000);
		  int recv_flag = obj.ReadData((char*)&ack, 1);
		  if (recv_flag != 0)
		  {
			  if (int(ack) == 88)
			  {
				  obj.Close();
				  return port_num;
			  }				  
		  }
		  obj.Close();
		  if (port_num == 200)
			  return 0;
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	CMySerialPort obj;
	unsigned char msg=4;
	unsigned char prev_msg = 4;
	//add getport function
	obj.Open(12, 9600);
	while (1)
	{
		int recv_flag = obj.ReadData((char*)&msg, 1); //the num of read byte
		if (recv_flag != 0)
		{
			if (int(msg) != int(prev_msg))
			{
				prev_msg = msg;
				int tran_msg = int(msg);
				if (tran_msg == 0)
					cout << tran_msg << " :no ball!" << endl;
				else if (tran_msg == 1)
					cout << tran_msg << " :has ball no hit!" << endl;
				else if (tran_msg == 2)
					cout << tran_msg << " :has ball hit valid!" << endl;
				else if (tran_msg == 3)
					cout << tran_msg << " :has ball hit invalid!" << endl;
				else
					cout << "error!" << endl;
			}	
		}
	}
	return 0;
}

