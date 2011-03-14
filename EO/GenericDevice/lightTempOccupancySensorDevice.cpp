
#include "lightTempOccupancySensorDevice.h"
#include "genericDevice.h"
#include <string>

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
      //TODO
      return 0;
    }
