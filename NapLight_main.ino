#include <Arduino.h>
#include <Wire.h>
#include <RTClib.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>
#include "NapLight.h"
#include "Snake.h"

NapLight nl;
void setup()
{
  SPI.begin();
  Wire.begin();
  nl.rtc.adjust(DateTime(__DATE__, __TIME__));
  nl.onlist[0] = Time(7,0); //7:00 AM
  nl.onlist[1] = Time(15,30); //3:30 PM
}

void loop() 
{
  nl.step();
}
