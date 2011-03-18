#include "Rocker2Device.h"
#include "genericDevice.h"
#include <string>
#include <sstream>
#include <bitset>

#include <stdio.h>
#include <stdlib.h>

Rocker2Device::Rocker2Device()
{
	addAttribute("State");
	addAttribute("FirstAction");
	addAttribute("SecondAction");           
}

int Rocker2Device::parse(Trame trame)
{
	bitset<8> DB3 (trame[0]);
	int DB2 = trame[1];
	int DB1 = trame[2];
	int DB0 = trame[3];

	setValue("State","on");
	
	bitset<8> message (status);

	bitset<4> firstAction;
	firstAction[3] = 0;
	firstAction[2] = DB3[0];
	firstAction[1] = DB3[1];
	firstAction[0] = DB3[2];
	switch (message[3])
	{
	case 0 :  //N-Message	
	//setValue("FirstAction",firstAction.to_string());
		if (char(firstAction.to_ulong()) == 0x00)
		setValue("FirstAction","AI");
		else if (char(firstAction.to_ulong())== 0x01)
		setValue("FirstAction","AO");
		else if (char(firstAction.to_ulong())== 0x02)
		setValue("FirstAction","BO");
		else if (char(firstAction.to_ulong())== 0x03)
		setValue("FirstAction","BI");
		
		if (DB3[7] == 1)  //2nd Action valid
		{
			bitset<4> secondAction;
			secondAction[3] = 0;
			secondAction[2] = DB3[4];
			secondAction[1] = DB3[5];
			secondAction[0] = DB3[6];
					
			if (secondAction.to_ulong()==0x00)
			setValue("SecondAction","AI");
			else if (secondAction.to_ulong()==0x01)
			setValue("SecondAction","AO");
			else if (secondAction.to_ulong()==0x02)
			setValue("SecondAction","BO");
			else if (secondAction.to_ulong()==0x03)
			setValue("SecondAction","BI");
		}
		else
		setValue("SecondAction","No secondAction");
		/* Envoyer le mode d'appui : pressé ou relaché
				if (DB3[3]==0)
				released;
				else
				pressed;
				*/
	break;
	case 1 :  //U-message
		if (firstAction == 0x00)
			setValue("FirstAction","no button");
		else if (firstAction == 0x03)
			setValue("FirstAction","buttons pressed simultaneously");
		
		setValue("SecondAction","No secondAction");
		
		/* Envoyer le mode d'appui : pressé ou relaché
				if (DB3[3]==0)
				released;
				else
				pressed;
				*/
		break;
	}

	return 0;
}
