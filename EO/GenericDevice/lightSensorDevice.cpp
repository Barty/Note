
#include "lightSensorDevice.h"
#include "genericDevice.h"
#include <string>

    lightSensorDevice::lightSensorDevice()
    {        
        addAttribute("State");
        addAttribute("ValueVoltage");
        addAttribute("UnitVoltage");
        addAttribute("ValueIllumination");
        addAttribute("UnitIllumination");
        addAttribute("Type");
        addAttribute("EventType");
    }
    
    int tempDevice::parse(*char trame)
    {
      bitset<8>(trame[0]) DB0;
      bitset<8>(trame[1]) DB1;
      bitset<8>(trame[2]) DB2;
      bitset<8>(trame[3]) DB3;
      
      attributs["State"] = "ON";
      attributs["ValueVoltage"] = DB3*5.1/255;
      if (attributs["Type"] == "1")
      /*  Range 300 lx to 60000 lx  */
      {
        if (DB0[0] == 0)                     //Range acc. to DB1 (300 to 30000 lx)
          attributs["ValueIllumination"] =   (DB1 * (30000 - 300) / 255) + 300;
        else                                 //Range acc. to DB2 (600 to 60000 lx)
          attributs["ValueIllumination"] =   (DB2 * (60000 - 600) / 255) + 600;
      }
      else
      /*  Range 0 lx to 1024 lx  */
      {
        if (DB0[0] == 0)                     //Range acc. to DB1 (0 to 510 lx)
          attributs["ValueIllumination"] =   DB1 * 510 / 255;
        else                                 //Range acc. to DB2 (0 to 1024 lx)
          attributs["ValueIllumination"] =   DB2 * 1024 / 255;
      }
      return 0;
    }