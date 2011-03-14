#ifndef __TEMPDEVICE_H
#define __TEMPDEVICE_H

#include <string>
#include <map>

#include "genericDevice.h"
#include "genericAttribute.h"

using namespace std;

class tempDevice : public genericDevice {

    public :
        tempDevice();
        virtual int parse(Trame trame);
    
    protected:
        map<string, genericAttribute*> attributs;
    };
    
#endif /* __TEMPDEVICE_H */
