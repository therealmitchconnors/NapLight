//#include <Wire.h>
//#include <RTClib.h>
#include "Snake.h"
#include "NapLight.h"

//DateTime NapLight::onlist;
//int NapLight::duration; // in seconds

//Snake NapLight::snake (10);

//DateTime NapLight::prevStep;
//DateTime NapLight::currStart;

//NapLight::NapLight()
//{
//  snake = new Snake(10,0xA0);
//}

void NapLight::addOnTime(DateTime d) {
  DateTime result[sizeof(onlist) + 1];
  for(int i=0; i<sizeof(onlist); i++) {
    result[i] = onlist[i];
  }
  result[sizeof(onlist)] = d;
  onlist = result;
}

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
            DateTime d = onlist[i];
            if(prevStep < d && now >= d)
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

