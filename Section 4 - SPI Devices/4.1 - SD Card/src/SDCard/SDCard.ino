#include <SPI.h>
#include <SD.h>

const int chipSelect = 10;

void setup() {
  Serial.begin(9600); 
  Serial.print("Initializing SD card...");
 
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");   
    while(1);
  }
  Serial.println("card initialized.");
}
 
void loop() {  
  File dataFile = SD.open("myFile.txt", FILE_WRITE);
  String dataString = "Hello World";  
  dataFile.println(dataString);
  dataFile.close();   
  Serial.println(dataString); 
  delay(1000);
}
