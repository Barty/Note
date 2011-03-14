#ifndef __2ROCKERDEVICE_H
#define __2ROCKERDEVICE_H

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
    
#endif /* __2ROCKERDEVICE_H */
