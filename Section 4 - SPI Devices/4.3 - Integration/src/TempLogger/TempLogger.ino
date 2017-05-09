#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

int BME_CS = 9;
int SD_CS = 10;

float sealevel = 1013.25;

Adafruit_BME280 bme(BME_CS);

void setup() {
    Serial.begin(9600); 
    Serial.println("Starting Temp Logger");  
      
    if (!SD.begin(SD_CS)) {
        Serial.println("SDCard Failed or Not Present");   
        return;
    }  
   
    if (!bme.begin()) {
        Serial.println("BME280 Failed or Not Present");
        return 0;
    }   
    delay(100);
}
void loop() {
    float temp = bme.readTemperature();
    int time = millis()/1000;
    writeData(temp, time);
    Serial.print(time);
    Serial.print(",");
    Serial.println(temp);
    delay(3000);
}

float readTemp(){      
    float temp = bme.readTemperature();
    SPI.end();
    return temp;
}

void writeData(float temp, int time){   
    File dataFile = SD.open("templog.txt", FILE_WRITE);
    if (dataFile) {
       dataFile.print(time);
       dataFile.print(" ");
       dataFile.println(temp);
       dataFile.close();   
    } 
    else {
      Serial.println("error opening file");
    }
   
}

