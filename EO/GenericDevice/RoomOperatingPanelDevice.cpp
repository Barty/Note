
#include "RoomOperatingPanelDevice.h"
#include "genericDevice.h"
#include <string>

    RoomOperatingPanelDevice::RoomOperatingPanelDevice()
    {   
        addAttribute("State");
        addAttribute("valueTemperature");
        addAttribute("UnitIntensity");
        addAttribute("valueSetPoint");
        addAttribute("valueFanSpeed");
        addAttribute("StageFanSpeed");
        addAttribute("valueDayNight");
        addAttribute("valueOccupancy");
        addAttribute("valueWindow");
        addAttribute("valueHumidity");
        addAttribute("UnitHumidity");
    }
    
    
    int RoomOperatingPanelDevice::parse(Trame trame)
    {
      //TODO
      return 0;
    }
