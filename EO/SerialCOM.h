#pragma comment (lib, "ftd2xx.lib")
//Defines
#define OPENING_FAILED -1
#define GET_PORT_FAILED -2
#define NO_PORT_INSTALLED -3
#define INVALID_HANDLE -4
#define PORT_OPEN 0;

//Include
#include <windows.h>
#include <stdio.h>
#include "ftd2xx.h"

class SerialCOM
{
public:
	SerialCOM();
	int openPort();
	int read();
	int write(char*);
	int close();
	~SerialCOM();


protected:
	FT_HANDLE fthandle;
	FT_STATUS res;
	FT_STATUS ftStatus;
	LONG COMPORT;
};

