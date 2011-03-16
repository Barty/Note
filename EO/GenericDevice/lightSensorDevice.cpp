
#include "lightSensorDevice.h"
#include "genericDevice.h"
#include <string>
#include <sstream>
#include <bitset>

#include <stdio.h>
#include <stdlib.h>

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
        int DB3 = trame[0];
        int DB2 = trame[1];
        int DB1 = trame[2];
        bitset<8> DB0 (trame[3]);

      
        setValue("State","on");
        
        std::ostringstream oss;
        oss <<  DB3*5.1/255;
        setValue("ValueVoltage", oss.str());
        
        if (type == 0x01)
        /*  Range 300 lx to 60000 lx  */
        {
            if (DB0[7] == 0)                     //Range acc. to DB1 (300 to 30000 lx)
            {
                std::ostringstream oss;
                oss << (DB1 * (30000 - 300) / 255) + 300;
                setValue("ValueIllumination", oss.str());
            }
            else                                 //Range acc. to DB2 (600 to 60000 lx)
            {
                std::ostringstream oss;
                oss << (DB2 * (60000 - 600) / 255) + 600;
                setValue("ValueIllumination", oss.str());
            }
        }

        if (type == 0x02)
        /*  Range 0 lx to 1024 lx  */
        {
            if (DB0[7] == 0)                     //Range acc. to DB1 (0 to 510 lx)
            {
                std::ostringstream oss;
                oss << DB1 * 510 / 255;
                setValue("ValueIllumination", oss.str());
            }
            else                                 //Range acc. to DB2 (0 to 1024 lx)
            {
                std::ostringstream oss;
                oss <<  DB2 * 1024 / 255;
                setValue("ValueIllumination", oss.str());
            }
        }
        return 0;
    }
