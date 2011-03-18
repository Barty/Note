#ifndef GASSENSORDEVICE_H
#define GASSENSORDEVICE_H

#include <string>
#include <map>

#include "genericDevice.h"
#include "genericAttribute.h"

class gasSensorDevice : public genericDevice {

public :
    lightSensorDevice();
    virtual int parse(Trame trame);

protected:
    map<string, genericAttribute*> attributs;
};


#endif // GASSENSORDEVICE_H
