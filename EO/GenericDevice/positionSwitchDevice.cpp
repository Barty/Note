
#include "positionSwitchDevice.h"
#include "genericDevice.h"
#include <string>

    positionSwitchDevice::positionSwitchDevice()
    {        
        addAttribute("State");
        addAttribute("Position");
        addAttribute("EventType");
    }
    
    int positionSwitchDevice::parse(Trame trame)
    {
      //TODO
      return 0;
    }
