
#include "windowContactDevice.h"
#include "genericDevice.h"
#include <string>

    windowContactDevice::windowContactDevice()
    {        
        addAttribute("State");
        addAttribute("value");
        addAttribute("EventType");
    }
    
    int windowContactDevice::parse(Trame trame)
    {
      //TODO
      return 0;
    }
