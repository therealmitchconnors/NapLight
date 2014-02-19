#include <Arduino.h>
#include <Wire.h>
#include <RTClib.h>
#include <StandardCplusplus.h>
#include <vector>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>
#include "NapLight.h"
#include "Snake.h"

//NapLight nl;
void setup()
{
  SPI.begin();
  Wire.begin();
}

void loop() 
{
//  nl.step();
}
