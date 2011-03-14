#ifndef __LIGHTTEMPOCCUPANCYSENSORDEVICE_H
#define __LIGHTTEMPOCCUPANCYSENSORDEVICE_H

#include <string>
#include <map>

#include "genericDevice.h"
#include "genericAttribute.h"

using namespace std;

class lightTempOccupancySensorDevice : public genericDevice {

    public :
        lightTempOccupancySensorDevice();
        virtual int parse(Trame trame);
    
    protected:
        map<string, genericAttribute*> attributs;
    };
    
#endif /* __LIGHTTEMPOCCUPANCYSENSORDEVICE_H */
