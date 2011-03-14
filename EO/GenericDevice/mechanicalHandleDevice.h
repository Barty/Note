#ifndef __MECHANICALHANDLEDEVICE_H
#define __MECHANICALHANDLEDEVICE_H

#include <string>
#include <map>

#include "genericDevice.h"
#include "genericAttribute.h"

using namespace std;

class mechanicalHandleDevice : public genericDevice {

    public :
        mechanicalHandleDevice();
        virtual int parse(Trame trame);
    
    protected:
        map<string, genericAttribute*> attributs;
    };
    
#endif /* __MECHANICALHANDLEDEVICE_H */
