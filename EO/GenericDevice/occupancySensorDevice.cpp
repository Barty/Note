
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
      //TODO
      return 0;
    }
