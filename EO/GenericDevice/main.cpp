#include <iostream>
#include "genericDevice.h"
#include "tempDevice.h"

using namespace std;

int main()
{
    genericDevice dev;
    cout << "//// Test - EnOcean Device Cache ////" << endl;
    
    dev.addAttribute("test");
    
    cout << dev.getValue("test") << endl;
    
    dev.setValue("test","43");
    
    cout << dev.getValue("test") << endl;

    cout << "//// Test - EnOcean Temperature Device ////" << endl;

    tempDevice dev2;
    Trame trame = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    
    cout << dev2.parse(trame) << endl;

    return 0;
}
