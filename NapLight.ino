//#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>
//#include <Wire.h>
#include <RTClib.h>
#include "NapLight.h"
#include "Snake.h"

NapLight nl;
void setUp()
{
  SPI.begin();
  Wire.begin()
}

void loop() 
{
  nl.step();
}
