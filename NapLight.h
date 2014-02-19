
#ifndef NapLight_h
#define NapLight_h
#include <RTClib.h>
#include "Snake.h"

class NapLight 
{
public:
    int duration; // in seconds
    void step();
    NapLight() : prevStep (0), currStart(0), snake(10) { rtc.begin(); }
    Time onlist[8];
    RTC_DS1307 rtc;
private:
    Snake snake;// (10);
    DateTime prevStep;
    DateTime currStart;
    void turnOff();
    void turnOn(DateTime);
    bool isOn();
};

#endif
