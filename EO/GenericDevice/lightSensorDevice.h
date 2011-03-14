#ifndef __LIGHTSENSORDEVICE_H
#define __LIGHTSENSORDEVICE_H

#include <string>
#include <map>

#include "genericDevice.h"
#include "genericAttribute.h"

using namespace std;

class lightSensorDevice : public genericDevice {

    public :
        lightSensorDevice();
        virtual int parse(Trame trame);
    
    protected:
        map<string, genericAttribute*> attributs;
    };
    
#endif /* __LIGHTSENSORDEVICE_H */
