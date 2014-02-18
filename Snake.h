#ifndef Snake_h
#define Snake_h

#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>

class Snake
{
public:
	Snake(int pinCS, int pinRandom = 0xA0);
	void shutDown(bool powerSave);
	void step();
private:
	Max72xxPanel matrix;
	static const int length;

	int* x, y;
	int ptr, nextPtr;

	boolean occupied(int ptrA);
	int next(int ptr);
	boolean equal(int ptrA, int ptrB);
}

#endif
