#include <SevenSeg.h>
SevenSeg sevenSeg;

void setup() {   
  sevenSeg.setup(); 
}

void loop() {   
 int num = random(9999);
 sevenSeg.display(num, 2000);
}

