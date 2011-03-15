#include <string>

#include "genericAttribute.h"

    genericAttribute::genericAttribute():readable(false)
    {
    }
    

    std::string genericAttribute::getValue()
    {
        static int now;
        // now = gettime
    
        if (readable)
        {
            return value;
        }
        else
        {
            return "not available";
            // TODO mettre des contrôles d'erreurs sur getValue
        }
    }
    
    void genericAttribute::setValue(std::string value)
    {
        this->value = value;
        readable = true;
        //timeRead = now;
    }
    
    void genericAttribute::flush()
    {
        readable = false;
    }
    
