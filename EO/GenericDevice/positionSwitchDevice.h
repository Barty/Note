#ifndef __POSITIONSWITCHDEVICE_H
#define __POSITIONSWITCHDEVICE_H

#include <string>
#include <map>

#include "genericDevice.h"
#include "genericAttribute.h"

using namespace std;

class positionSwitchDevice : public genericDevice {

    public :
        positionSwitchDevice();
        virtual int parse(Trame trame);
    
    protected:
        map<string, genericAttribute*> attributs;
    };
    
#endif /* __POSITIONSWITCHDEVICE_H */
