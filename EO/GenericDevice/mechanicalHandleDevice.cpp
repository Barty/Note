
#include "mechanicalHandleDevice.h"
#include "genericDevice.h"
#include <string>

    mechanicalHandleDevice::mechanicalHandleDevice()
    {        
        addAttribute("State");
        addAttribute("Value");
        addAttribute("EventType");
    }
    
    int mechanicalHandleDevice::parse(Trame trame)
    {
      //TODO
      return 0;
    }
