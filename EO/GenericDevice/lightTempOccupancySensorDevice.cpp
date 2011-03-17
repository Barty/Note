
#include "lightTempOccupancySensorDevice.h"
#include "genericDevice.h"
#include <string>
#include <sstream>
#include <bitset>

#include <stdio.h>
#include <stdlib.h>

lightTempOccupancySensorDevice::lightTempOccupancySensorDevice()
{
    addAttribute("State");
    addAttribute("ValueTemperature");
    addAttribute("ValueIntensity");
    addAttribute("ValueOccupancy");
    addAttribute("UnitTemperature");
    addAttribute("UnitIntensity");
    addAttribute("EventType");
}
    
int lightTempOccupancySensorDevice::parse(Trame trame)
{
    int DB3 = trame[0];
    int DB2 = trame[1];
    int DB1 = trame[2];
    bitset<8> DB0 (trame[3]);

    setValue("State","on");

    std::ostringstream oss;
    oss <<  DB3*5.1/255;

    switch (type) {

    case 0x01:
        oss.clear();
        oss << (DB2*510/255);
        setValue("ValueIntensity", oss.str());

        oss.clear();
        oss << (DB3 *51/255);
        setValue("ValueTemperature", oss.str());
        break;

    case 0x02:
        oss.clear();
        oss << (DB2*1020/255);
        setValue("ValueIntensity", oss.str());

        oss.clear();
        oss << (DB3 *51/255);
        setValue("ValueTemperature", oss.str());
        break;

    default:
        oss.clear();
        oss << (DB2*1530/255);
        setValue("ValueIntensity", oss.str());

        oss.clear();
        oss << (DB3*80/255)-30;
        setValue("ValueTemperature", oss.str());
        break;
    }

    switch (DB0[7]) {
    case 0:
        setValue("ValueOccupancy", "on");
        break;
    default:
        setValue("ValueOccupancy", "off");
        break;
    }


    return 0;
}
