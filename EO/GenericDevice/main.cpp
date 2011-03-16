#include <iostream>
#include "genericDevice.h"
#include "lightSensorDevice.h"

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

    lightSensorDevice dev2;
    char trame[4] = {9,0,0,0};
    //Trame trame = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    
    cout << dev2.parse(trame) << endl;
    cout << "State : " << dev2.getValue("State") << endl;
    cout << "Voltage : " << dev2.getValue("ValueVoltage") << endl;
    cout << "Illumination : " << dev2.getValue("ValueIllumination") << endl;

    return 0;
}
