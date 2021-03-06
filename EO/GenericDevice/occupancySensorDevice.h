#ifndef __OCCUPANCYSENSORDEVICE_H
#define __OCCUPANCYSENSORDEVICE_H

#include <string>
#include <map>

#include "genericDevice.h"
#include "genericAttribute.h"

using namespace std;

class occupancySensorDevice : public genericDevice {

    public :
        occupancySensorDevice();
        virtual int parse(Trame trame);
    
    protected:
        map<string, genericAttribute*> attributs;
    };
    
#endif /* __OCCUPANCYSENSORDEVICE_H */
