#include "genericDevice.h"
#include <string>

    genericDevice::genericDevice()
    {
    }
    
    genericDevice::~genericDevice()
    {
    }
    
    void genericDevice::flush()
    {
        static map<string, genericAttribute*>::const_iterator it;
        for( it = attributs.begin() ; it!=attributs.end() ; ++it)
        {
            it->second->flush();
        }   
    }    
    
    
    int genericDevice::setValue(std::string key, std::string value)
    {
        attributs[key]->setValue(value);
    }

    // example
    std::string genericDevice::getValue(std::string key)
    {
        return attributs[key]->getValue();
    }
    
    void genericDevice::addAttribute(std::string key)
    {
        attributs.insert( pair<std::string, genericAttribute*>(key, new genericAttribute()) );
    }
    
    int genericDevice::getDeviceStatus()
    {
        // EnOcean ne permet pas de récupérer le status du device.
        return -1;
    }
    
    void genericDevice::setType(char type)
    {
        this.type = type;
    }
    
    int genericDevice::parse(Trame trame)
    {
        return -1;
    }
