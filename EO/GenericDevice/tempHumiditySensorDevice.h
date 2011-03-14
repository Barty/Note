#ifndef __TEMPHUMIDITYSENSORDEVICE_H
#define __TEMPHUMIDITYSENSORDEVICE_H

#include <string>
#include <map>

#include "genericDevice.h"
#include "genericAttribute.h"

using namespace std;

class tempHumiditySensorDevice : public genericDevice {

    public :
        tempHumiditySensorDevice();
        virtual int parse(Trame trame);
    
    protected:
        map<string, genericAttribute*> attributs;
    };
    
#endif /* __TEMPHUMIDITYSENSORDEVICE_H */
