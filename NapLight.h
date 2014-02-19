
#ifndef NapLight_h
#define NapLight_h

//#include <Arduino.h>
//#include <Wire.h>
//#include <StandardCplusplus.h>
//#include <vector>
#include <RTClib.h>
#include "Snake.h"

class NapLight 
{
public:
    int duration; // in seconds
    void step();
    NapLight() : prevStep (0), currStart(0), snake(10) {}
    void addOnTime(DateTime);
private:
    DateTime onlist[0];
    Snake snake;// (10);
    DateTime prevStep;
    DateTime currStart;
    void turnOff();
    void turnOn(DateTime);
    bool isOn();
    RTC_DS1307 rtc;
};

#endif
