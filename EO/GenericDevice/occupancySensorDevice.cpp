
#include "occupancySensorDevice.h"
#include "genericDevice.h"
#include <string>

occupancySensorDevice::occupancySensorDevice()
{
    addAttribute("State");
    addAttribute("Value");
    addAttribute("EventType");
}

int occupancySensorDevice::parse(Trame trame)
{
    char DB1 = trame[2];

    this->setValue("State","ON");
    //attributs["State"] = "ON";

    switch (type)
    {
    case "1":
        if (DB1 < 127)
            attributs["Value"].setValue("on");
        if (DB1 > 127)
            attributs["Value"].setValue("off");
    break;

    default:
      ///// TODO ERROR ! /////
    break;
    }
    return 0;
}
