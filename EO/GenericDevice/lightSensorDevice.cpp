
#include "lightSensorDevice.h"
#include "genericDevice.h"
#include <string>
#include <bitset>

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
    
    int lightSensorDevice::parse(char* trame)
    {
      bitset<8> DB3 (trame[0]);
      bitset<8> DB2 (trame[1]);
      bitset<8> DB1 (trame[2]);
      bitset<8> DB0 (trame[3]);

      
      attributs.setValue("State","on");
      int voltage = DB3*5.1/255;
      attributs.setValue("ValueVoltage",itoa(voltage));
      if (attributs.getvalue("Type","0x01"))
      /*  Range 300 lx to 60000 lx  */
      {
        if (DB0[0] == 0)                     //Range acc. to DB1 (300 to 30000 lx)
          {
          int temp = (DB1 * (30000 - 300) / 255) + 300;
          attributs.setValue("ValueIllumination",itoa(temp));
          }
        else                                 //Range acc. to DB2 (600 to 60000 lx)
        {
          int temp = (DB2 * (60000 - 600) / 255) + 600;
          attributs.setValue("ValueIllumination",itoa(temp));
        }
      }
      else
      /*  Range 0 lx to 1024 lx  */
      {
        if (DB0[0] == 0)                     //Range acc. to DB1 (0 to 510 lx)
        {
          int temp =   DB1 * 510 / 255;
          attributs.setValue("ValueIllumination",itoa(temp));
        }
        else                                 //Range acc. to DB2 (0 to 1024 lx)
        {
          int temp =   DB2 * 1024 / 255;
          attributs.setValue("ValueIllumination",itoa(temp));
        }
      }
      return 0;
    }