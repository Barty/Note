#include "2RockerDevice.h"
#include "genericDevice.h"
#include <string>

    tempDevice::tempDevice()
    {
        attributs["State"] = new genericAttribute();
        attributs["Value"] = new genericAttribute(); 
        attributs["Type"] = new genericAttribute();              
    }
    
    int tempDevice::parse(Trame trame)
    {
      attributs["State"] = "ON";
      if (attributs["Type"] == "1")
      /*Light and Blind Control - Application Style 1*/
      {
        switch ()
        {
          case 0b000 :  //Button AI 
          attributs["Value"] = "AI";
          break;
          
          case 0b001 :  //Button AO
          attributs["Value"] = "AO";
          break;
          
          case 0b010 :  //Button BI
          attributs["Value"] = "BI";
          break;
          
          case 0b011 :  //Button BO
          attributs["Value"] = "BO";
          break;
        }
      }
      else
      {
      }
      return 0;
    }
