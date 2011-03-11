#include "SerialCOM.h"
#include <string>
#include <iostream>

using namespace std;

SerialCOM::SerialCOM()
{
	//TODO : Initialiser les variables.
}

/*int openPort():
permet de se connecter au gateway USB
renvoie le numéro du port COM.
*/
int SerialCOM::openPort()
{
	res = FT_Open(0, &fthandle);

	if(res != FT_OK)
	{				
		return OPENING_FAILED;
	}
	 
	
	res = FT_GetComPortNumber(fthandle,&COMPORT);

	if(res != FT_OK){
				
		
		return GET_PORT_FAILED;
	}

	if (COMPORT == -1){

		return NO_PORT_INSTALLED;
	}

	return COMPORT;
}

/*
int read() :
Permet de lire 
*/
int SerialCOM::read()
{
	//TODO : premiere lecture , débug adrien ou baptiste
	DWORD EventDWord; 
	DWORD TxBytes; 
	DWORD RxBytes; 
	DWORD BytesReceived = 0; 
	unsigned char RxBuffer[255]; 		
	
	
	//FT_GetStatus(fthandle,&RxBytes,&TxBytes,&EventDWord); pas nécessaire

	ftStatus = FT_Read(fthandle,RxBuffer,14,&BytesReceived); 
	if (ftStatus == FT_OK && BytesReceived != 0) 
	{ 
		//RxBuffer[BytesReceived]='X';
		//RxBuffer[BytesReceived+1]='\0';
		for (int i=0;i<BytesReceived;i++)
			std::cout<<std::hex <<static_cast<int>(RxBuffer[i])<<" ";//
		cout<<endl;
		return BytesReceived;
	} 
	else 
		if (ftStatus != FT_OK)
	{ 
		std::cout<<"Erreur Lecture"<<std::endl;
	}
	
	return 0;
} 
	
int SerialCOM::write(char* data)
{
	 //IDBASE = a5 5a 8b 98 ff c6 ef 80
	DWORD BytesWritten; 
	char RD_IDBASE[14];
		//Test:
	/*Construction d'une trame pour récuperer L'IDBASE
	TODO : a supprimer
	RD_IDBASE[0] = 0xA5;
	RD_IDBASE[1] = 0x5A;
	RD_IDBASE[2] = 0xAB;
    RD_IDBASE[3] = 0x58;
	RD_IDBASE[4] = 0x00;
	RD_IDBASE[5] = 0x00;
	RD_IDBASE[6] = 0x00;
	RD_IDBASE[7] = 0x00;
	RD_IDBASE[8] = 0x00;
	RD_IDBASE[9] = 0x00;
	RD_IDBASE[10] = 0x00;
	RD_IDBASE[11] = 0x00;
	RD_IDBASE[12] = 0x00;	
	//Checksum
	RD_IDBASE[13] = (char) (RD_IDBASE[2] + RD_IDBASE[3]);

	char TxBuffer[256]; // Contains data to write to device 
	*/

	//TODO modifier le champs de l'écriture
 
	ftStatus = FT_Write(fthandle, data, sizeof(RD_IDBASE), &BytesWritten); 
	 if (ftStatus == FT_OK) 
	 { 
		 //TODO : à supprimer
		 std::cout<<"Ecriture réussie"<<std::endl;
	 } 
	else 
	 { 
		 std::cout<<"Erreur Ecriture "<<std::endl;
     } 
	 //TODO : modifier le return
return 0;	 
} 


int SerialCOM::close()
{
	//TODO : modifier le return
	return FT_Close(fthandle);
}


SerialCOM::~SerialCOM()
{
	//TODO
}
