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
            if(onlist[i].hour() > 24){
              // This is like a 'null' time, since arrays are fixed length.
              break;
            }
            DateTime d = onlist[i].prevOccurence(now);
            if(debug && prevStep < d && now >= d && prevStep != DateTime(0))
            {
                Serial.println("**********");
                Serial.print("Turning on at: ");
                printDate(now);
                Serial.print("For time: ");
                printTime(onlist[i]);
                Serial.print("previous occurence: ");
                printDate(d);
                Serial.println("********");
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


void NapLight::turnOn(int thisDuration) { 
  turnOn(DateTime(rtc.now().unixtime() + thisDuration - duration)); 
}


void NapLight::printTime(Time t) {
  Serial.print(t.hour(), DEC);
  Serial.print(':');
  Serial.print(t.minute(), DEC);
  Serial.print(':');
  Serial.print(t.second(), DEC);
  Serial.println();
}
//
void NapLight::printDate(DateTime d){
  Serial.print(d.year(), DEC);
  Serial.print('/');
  Serial.print(d.month(), DEC);
  Serial.print('/');
  Serial.print(d.day(), DEC);
  Serial.print(' ');
  Serial.print(d.hour(), DEC);
  Serial.print(':');
  Serial.print(d.minute(), DEC);
  Serial.print(':');
  Serial.print(d.second(), DEC);
  Serial.println();
}
