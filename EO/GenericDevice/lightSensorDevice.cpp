
#include "lightSensorDevice.h"
#include "genericDevice.h"
#include <string>

    lightSensorDevice::lightSensorDevice()
    {        
        addAttribute("State");
        addAttribute("Value");
        addAttribute("Unit");
        addAttribute("EventType");
    }
    
    int lightSensorDevice::parse(Trame trame)
    {
      //TODO
      return 0;
    }
