// sensor_demo.cpp : Defines the entry point for the console application.
//
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include "serialPortdll.h"
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	static unsigned int msg = 0;
	static unsigned int prev_msg = 0;
	int com_num = get_com_num();
	if (com_num == 0)
		std::cout << "no valid com port!" << std::endl;
	else
	{
		open_com_port(com_num);
		while (1)
		{
			msg = fetch_msg();

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
			}

		}
	}
	return 0;
}

