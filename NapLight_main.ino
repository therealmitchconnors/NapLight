#include <Arduino.h>
#include <Wire.h>
#include <RTClib.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>
#include "NapLight.h"
#include "Snake.h"
//#include <Serial.h>

NapLight nl;
void setup()
{
  SPI.begin();
  Wire.begin();
  nl.rtc.adjust(DateTime(__DATE__, __TIME__));
  nl.onlist[0] = Time(7,0); //7:00 AM
  nl.onlist[1] = Time(15,30); //3:30 PM
  //debugSetup();
}

void loop() 
{
  //debug();
  nl.step();
  delay(200);
}
//
//void debugSetup() {
//  Serial.begin(9600);
//  Time t = nl.onlist[1];
//  DateTime now = nl.rtc.now();
//  Serial.print("Startup time is: ");
//  printDate(now);
//  Serial.print("Target alarm time: ");
//  printTime(t);
//  Serial.print("Previous occurence of time: ");
//  printDate(t.prevOccurence(now));
//  Serial.print("Next occurence of time: ");
//  printDate(t.nextOccurence(now));
//  Serial.println(now.compare(t.nextOccurence(now)));
//  Serial.print("previous when now: ");
//  printDate(now.getTime().prevOccurence(now));
//  Serial.print("next when now: ");
//  printDate(now.getTime().nextOccurence(now));
//}
//
//void debug() {
//  DateTime now = nl.rtc.now();
//  printDate(now);
//  Serial.print("previous step: ");
//  printDate(nl.prevStep);
//  Serial.print("snake is on: ");
//  Serial.println(nl.isOn());
//}
//
//void printTime(Time t) {
//  Serial.print(t.hour(), DEC);
//  Serial.print(':');
//  Serial.print(t.minute(), DEC);
//  Serial.print(':');
//  Serial.print(t.second(), DEC);
//  Serial.println();
//}
//
//void printDate(DateTime d){
//  Serial.print(d.year(), DEC);
//  Serial.print('/');
//  Serial.print(d.month(), DEC);
//  Serial.print('/');
//  Serial.print(d.day(), DEC);
//  Serial.print(' ');
//  Serial.print(d.hour(), DEC);
//  Serial.print(':');
//  Serial.print(d.minute(), DEC);
//  Serial.print(':');
//  Serial.print(d.second(), DEC);
//  Serial.println();
//}
