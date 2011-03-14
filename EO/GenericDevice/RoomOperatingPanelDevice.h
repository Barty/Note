#ifndef __ROOMOPERATINGPANELDEVICE_H
#define __ROOMOPERATINGPANELDEVICE_H

#include <string>
#include <map>

#include "genericDevice.h"
#include "genericAttribute.h"

using namespace std;

class roomOperatingPanelDevice : public genericDevice {

    public :
        roomOperatingPanelDevice();
        virtual int parse(Trame trame);
    
    protected:
        map<string, genericAttribute*> attributs;
    };
    
#endif /* __ROOMOPERATINGPANELDEVICE_H */
