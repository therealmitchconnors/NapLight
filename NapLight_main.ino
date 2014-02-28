#include <Arduino.h>
#include <Wire.h>
#include <RTClib.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>
#include "NapLight.h"
#include "Snake.h"
//#include <Serial.h>

NapLight nl (3600);
void setup()
{
  SPI.begin();
  Wire.begin();
//  nl.rtc.adjust(DateTime(__DATE__, __TIME__));
  nl.onlist[0] = Time(7,00); //7:00 AM
  nl.onlist[1] = Time(15,30); //3:30 PM
  nl.onlist[2] = Time(16,31); //4:31 PM
  nl.turnOn(60);
  debugSetup();
}

void loop() 
{
  debug();
  nl.step();
  delay(200);
}
//
void debugSetup() {
  nl.debug = true;
  Serial.begin(9600);
  Time t = nl.onlist[2];
  DateTime now = nl.rtc.now();
  Serial.print("Startup time is: ");
  nl.printDate(now);
  Serial.println("Target alarm times: ");
  nl.printTime(nl.onlist[0]);
  nl.printTime(nl.onlist[1]);
  nl.printTime(nl.onlist[2]);  
  nl.printTime(nl.onlist[3]);
  nl.printTime(nl.onlist[4]);
  nl.printTime(nl.onlist[5]);
  nl.printTime(nl.onlist[6]);  
  nl.printTime(nl.onlist[7]);
  Serial.print("Previous occurence of time: ");
  nl.printDate(t.prevOccurence(now));
  Serial.print("Next occurence of time: ");
  nl.printDate(t.nextOccurence(now));
  Serial.println(now.compare(t.nextOccurence(now)));
  Serial.print("previous when now: ");
  nl.printDate(now.getTime().prevOccurence(now));
  Serial.print("next when now: ");
  nl.printDate(now.getTime().nextOccurence(now));
}
//
int i;
void debug() {
  if(i<4){
    i++;
    return;
  }
  i = 0;
  DateTime now = nl.rtc.now();
  nl.printDate(now);
//  Serial.print("previous step: ");
//  printDate(nl.prevStep);
//  Serial.print("snake is on: ");
//  Serial.println(nl.isOn());
}
