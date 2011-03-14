#include "2RockerDevice.h"
#include "genericDevice.h"
#include <string>

    tempDevice::tempDevice()
    {
        attributs["State"] = new genericAttribute();
        attributs["Value"] = new genericAttribute();             
    }
    
    int tempDevice::parse(Trame trame)
    {
      
      return 0;
    }
