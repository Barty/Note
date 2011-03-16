
#include "occupancySensorDevice.h"
#include "genericDevice.h"
#include <string>

    occupancySensorDevice::occupancySensorDevice()
    {        
        addAttribute("State");
        addAttribute("Value");
        addAttribute("EventType");
    }
    
    int occupancySensorDevice::parse(char * trame)
    {
      char DB1 = trame[2];
      
      attributs["State"] = "ON";
      if (attributs["Type"] == "1")
      {
        if (DB1 < 127)
          attributs["Value"].setValue("on");
        if (DB1 > 127)
          attributs["Value"].setValue("off");
      }
      else
      {
      ///// TODO ERROR ! /////
      }
      return 0;
    }
