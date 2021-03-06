#ifndef __GENERICATTRIBUTE_H
#define __GENERICATTRIBUTE_H

#include <string>

class genericAttribute {

    public:
        genericAttribute();
        genericAttribute(std::string name);

        std::string getValue();
        void setValue(std::string value);
        //TODO trouver un pattern pour reglementer l'acces en lecture et en ecriture des attributs.
        void flush();

    private:

        std::string name;
        //protected string description;

        std::string value;
        bool readable;
        int timeRead;
    };
    
#endif /* __GENERICATTRIBUTE_H */
