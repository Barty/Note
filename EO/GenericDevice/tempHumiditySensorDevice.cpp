
#include "tempHumidityDevice.h"
#include "genericDevice.h"
#include <string>

    tempHumidityDevice::tempHumidityDevice()
    {        
        addAttribute("State");
        addAttribute("valueTemperature");
        addAttribute("UnitTemperature");
        addAttribute("valueHumidity");
        addAttribute("UnitHumidity");
        addAttribute("EventType");
    }
    
    int tempHumidityDevice::parse(Trame trame)
    {
      //TODO
      return 0;
    }
