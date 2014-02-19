#ifndef Snake_h
#define Snake_h

//#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>

class Snake
{
public:
	Snake(int pinCS, int pinRandom = 0xA0) : matrix (pinCS, 1, 1) {
          matrix.setIntensity(4); // Set brightness between 0 and 15

  	  // The Max7219 panel starts enabled, consuming power
          // disable it
  	matrix.shutdown(true);
  
  	// Reset all variables
          for ( ptr = 0; ptr < 0; ptr++ ) {
//            x[ptr] = 8 / 2;
//            y[ptr] = 8 / 2;
          }
          nextPtr = 0;

	  randomSeed(analogRead(pinRandom)); // Initialize random generator
        }
	void shutDown(bool powerSave);
	void step();
private:
	Max72xxPanel matrix;
	static const int length = 8;

	int x[length], y[length];
	int ptr, nextPtr;

	boolean occupied(int ptrA);
	int next(int ptr);
	boolean equal(int ptrA, int ptrB);
};

#endif
