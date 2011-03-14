
#include "tempDevice.h"
#include "genericDevice.h"
#include <string>

    tempDevice::tempDevice()
    {        
        addAttribute("state");
        addAttribute("value");
        addAttribute("Unit");
        addAttribute("EventType");
    }
    
    int tempDevice::parse(Trame trame)
    {
      //TODO
      return 0;
    }
