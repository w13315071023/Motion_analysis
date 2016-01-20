// serialPortdll.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "serialPortdll.h"
#include "getport.h"
#include "MySerialPort.h"
#include <iostream>
using namespace std;
using namespace lincoln_class;
CMySerialPort obj;

int get_com_num()
{
	return get_port_num(); //0: no valid port

}
bool open_com_port(int com_num)
{
	bool flag = obj.Open(com_num, 9600);
	if (flag)
		return TRUE;
	else
		return FALSE;
}
bool close_com_port(int com_num)
{
	bool flag = obj.Close();
	if (flag)
		return TRUE;
	else
		return FALSE;
}
static unsigned int prev_msg = 0;
unsigned int fetch_msg()
{	
	static unsigned int msg = 0;	
	int recv_flag = obj.ReadData((unsigned int*)&msg, 4); //the num of read byte
	if (recv_flag != 0&&msg >= 1 && msg <= 4)   //1:no ball; 2:has ball no hit; 3:has ball hit valid; 4:has ball hit invalid;
	{
		prev_msg = msg;
		return msg;
	}	
	return prev_msg;
}

