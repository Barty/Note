#ifndef __GENERICDEVICE_H
#define __GENERICDEVICE_H

#include <string>
#include <map>

#include "genericAttribute.h"

typedef char Trame[14]; //TODO à inclure de manière globale

using namespace std;

class genericDevice {

    public :
        genericDevice();
        virtual ~genericDevice();

        void flush(); // vide le cache du periphérique.

        // example
        std::string getValue(std::string key);
        int setValue(std::string key, std::string value);
        
        void addAttribute(std::string key);
        //string getUnit();
    
        virtual int parse(Trame trame);
    
        int getDeviceStatus();
    
        //void toXML();
    
    protected:
        int id;
        int type;
        map<string, genericAttribute*> attributs;
    };
    
#endif /* __GENERICDEVICE_H */
