#include <SevenSeg.h>
SevenSeg sevenSeg;

void setup() { 
  Serial.begin(9600);
  while(!Serial){}
  Serial.println("Starting 7 Segment"); 
  sevenSeg.setup(); 
}

void loop() {   
 int num = random(9999);
 sevenSeg.display(num, 2000);
}

