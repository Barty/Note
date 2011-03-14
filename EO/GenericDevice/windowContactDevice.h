#ifndef __WINDOWCONTACTDEVICE_H
#define __WINDOWCONTACTDEVICE_H

#include <string>
#include <map>

#include "genericDevice.h"
#include "genericAttribute.h"

using namespace std;

class windowContactDevice : public genericDevice {

    public :
        windowContactDevice();
        virtual int parse(Trame trame);
    
    protected:
        map<string, genericAttribute*> attributs;
    };
    
#endif /* __WINDOWCONTACTDEVICE_H */
