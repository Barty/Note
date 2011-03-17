#include "gasSensorDevice.h"
#include "genericDevice.h"

#include <string>
#include <sstream>
#include <bitset>

#include <stdio.h>
#include <stdlib.h>

gasSensorDevice::gasSensorDevice()
{
    addAttribute("State");
    addAttribute("ValueTemperature");
    addAttribute("UnitTemperature");
    addAttribute("ValueConcentration");
    addAttribute("UnitConcentration");
    addAttribute("ValueHumidity");
    addAttribute("UnitHumidity");
    addAttribute("Type");
    addAttribute("EventType");
}


gasSensorDevice::parse(Trame trame){
    int DB3 = trame[0];//?
    int DB2 = trame[1];//?
    int DB1 = trame[2];

    bitset<8> DB0 (trame[3]);
    std::ostringstream oss;

    setValue("State","on");

    switch (type) {

    case 0x01://CO+temperature

        oss<<DB3;
        oss<<DB2;
        setValue("ValueConcentration",oss);

        if (DB0[6]){//the temperature sensor available
           oss.clear();
           oss<<DB1;
           setValue("ValueTemperature",oss);
        }

        break;

    case 0x04: //CO2+temperature+humidity

        oss<<(DB2*10);
        setValue("ValueConcentration",oss);

        if (DB0[5]){//the humidity sensor available
           oss.clear();
           oss<<DB1*2; // /100*200
           setValue("ValueTemperature",oss);
        }

        if (DB0[6]){//the temperature sensor available
           oss.clear();
           oss<<DB3*5; // /51*255
           setValue("ValueTemperature",oss);
           //TODO: throw error in case out of range
        }


        break;

    default: //undefined type of gas
        //todo : throw error
        break;
    }


    return 0;
}
