
#ifndef NapLight_h
#define NapLight_h

//#include <Arduino.h>
//#include <Wire.h>
#include <StandardCplusplus.h>
#include <vector>
#include <RTClib.h>

class NapLight 
{
public:
    vector<DateTime> onlist;
    int duration; // in seconds
    void step();
    NapLight() : prevStep (0), currStart(0), snake(10) {};
private:
    Snake snake;// (10);
    DateTime prevStep;
    DateTime currStart;
    void turnOff();
    void turnOn(DateTime);
    bool isOn();
    RTC_DS1307 rtc;
};

#endif
