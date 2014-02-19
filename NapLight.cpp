//#include <Wire.h>
//#include <RTClib.h>
#include "Snake.h"
#include "NapLight.h"

void NapLight::step()
{
    DateTime now = rtc.now();
    if(isOn())
    {
        DateTime endTime (currStart.unixtime() + duration);
        // Should I turn off?
        if(prevStep < endTime && now >= endTime)
        {
            turnOff();
        } else {
            snake.step();
        }
    } else {
        for (int i=0; i < sizeof(onlist); i++)
        {
            DateTime d = onlist[i].prevOccurence(now);
            if(prevStep < d && now >= d && prevStep != DateTime(0))
            {
                turnOn(d);
                snake.step();
                break;
            }
        }
    }
    prevStep = now;
}

void NapLight::turnOff(){
    snake.shutDown(true);
    currStart = DateTime(0);
}

void NapLight::turnOn(DateTime apptTime)
{
    snake.shutDown(false);
    currStart = apptTime;
}

bool NapLight::isOn()
{
    return currStart != DateTime(0);
}

