#include "Arduino.h"
#include "SevenSeg.h"

SevenSeg::numberToDisplay(int num, int disp);
{
	Serial.println(num);
	Serial.println(disp);
	/*digitalWrite(disp, LOW);
  	displayNumber(num);
  	delay(1);
  	clearSegments();
  	digitalWrite(disp, HIGH);*/
}