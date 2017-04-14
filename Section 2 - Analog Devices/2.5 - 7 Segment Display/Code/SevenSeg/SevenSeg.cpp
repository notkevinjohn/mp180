#include "Arduino.h"
#include "SevenSeg.h"

SevenSeg::SevenSeg(){

}

void SevenSeg::numberToDisplay(int num, int disp)
{
	Serial.println(num);
	Serial.println(disp);	
}