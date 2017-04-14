#include <SevenSeg.h>
SevenSeg sevenSeg;

void setup() { 
  Serial.begin(9600);
  while(!Serial){}
  Serial.println("Starting 7 Segment");
}

void loop() {   
  sevenSeg.numberToDisplay(1,sevenSeg.d1());
 
}

