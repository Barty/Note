

#include <tchar.h>
#include "SerialCOM.h"
#include <iostream>


int _tmain(int argc, _TCHAR* argv[])
{
	SerialCOM test;
	char x='a';
	int n = test.openPort();
	

	std::cout<<"Connected on port "<<n<<std::endl;

	//Debug : création de trame de learning
	char ON[14];
	char OFF[14];
	ON[0] = 0xA5;
	ON[1] = 0x5A;
	ON[2] = 0x6B;
	ON[3] = 0x05;
	//Data
	ON[4] = 0x10;
	ON[5] = 0x00;
	ON[6] = 0x00;
	ON[7] = 0x00;
	//ID
	ON[8] = 0xFF;
	ON[9] = 0xC6;
	ON[10] = 0xEF;
	ON[11] = 0x80;
	//Status
	ON[12] = 0x30;
	//Checksum
	ON[13] = 0x00;
	for(int i = 2;i<13;i++)
	{
		ON[13]= (char)(ON[13] + ON[i]);
	}

	std::cin>>x;

	test.write(&ON[0]);
	

	Sleep(200);

	OFF[0] = 0xA5;
	OFF[1] = 0x5A;
	OFF[2] = 0x6B;
	OFF[3] = 0x05;
	OFF[4] = 0x00;
	OFF[5] = 0x00;
	OFF[6] = 0x00;
	OFF[7] = 0x00;
	//ID
	OFF[8] = 0xFF;
	OFF[9] = 0xC6;
	OFF[10] = 0xEF;
	OFF[11] = 0x80;
	//Status
	OFF[12] = 0x20;
	//Checksum
	OFF[13] = 0x00;
	for(int i = 2;i<13;i++)
	{
		OFF[13] = (char) (OFF[13] + OFF[i]);
	}

	test.write(&OFF[0]);
	

	

	while (x!='e')
	{
		
		test.read(); 

	}
	test.close();
	std::cin>>x;
	return 0;
}

