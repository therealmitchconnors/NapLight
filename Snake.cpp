//#include <Max72xxPanel.h>
#include "Snake.h"

void Snake::shutDown(bool powerSave)
{
	matrix.shutdown(powerSave);
}

void Snake::step()
{
	// Shift pointer to the next segment
	ptr = nextPtr;
	nextPtr = next(ptr);

	//matrix.drawPixel(x[ptr], y[ptr], HIGH); // Draw the head of the snake
	matrix.write(); // Send bitmap to display

	//delay(wait);

	if ( ! occupied(nextPtr) ) {
		//matrix.drawPixel(x[nextPtr], y[nextPtr], LOW); // Remove the tail of the snake
	}

	for ( int attempt = 0; attempt < 10; attempt++ ) {

		// Jump at random one step up, down, left, or right
		switch ( random(4) ) {
//		case 0: x[nextPtr] = constrain(x[ptr] + 1, 0, matrix.width() - 1); y[nextPtr] = y[ptr]; break;
//		case 1: x[nextPtr] = constrain(x[ptr] - 1, 0, matrix.width() - 1); y[nextPtr] = y[ptr]; break;
//		case 2: y[nextPtr] = constrain(y[ptr] + 1, 0, matrix.height() - 1); x[nextPtr] = x[ptr]; break;
//		case 3: y[nextPtr] = constrain(y[ptr] - 1, 0, matrix.height() - 1); x[nextPtr] = x[ptr]; break;
		}

		if ( ! occupied(nextPtr) ) {
		  break; // The spot is empty, break out the for loop
		}
	}
}

boolean Snake::occupied(int ptrA) {
  for ( int ptrB = 0 ; ptrB < length; ptrB++ ) {
    if ( ptrA != ptrB ) {
      if ( equal(ptrA, ptrB) ) {
        return true;
      }
    }
  }

  return false;
}

int Snake::next(int ptr) {
  return (ptr + 1) % length;
}

boolean Snake::equal(int ptrA, int ptrB) {
//  return x[ptrA] == x[ptrB] && y[ptrA] == y[ptrB];
return false;
}
