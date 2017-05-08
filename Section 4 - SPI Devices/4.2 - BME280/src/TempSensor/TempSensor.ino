#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

int chipSelect = 9;
float sealevel = 1013.25;

Adafruit_BME280 bme(chipSelect);

void setup() {
    Serial.begin(9600);
    Serial.println("initializing BME280...");     
    if (!bme.begin()) {
        Serial.println("BME280 Failed or Not Present");
        while (1);    
    } 
    Serial.println("...BME280 initialized");  
    Serial.println();  
    delay(1000); 
}

void loop() { 
    Serial.print("Temperature: ");
    Serial.print(bme.readTemperature());
    Serial.println(" C");

    Serial.print("Pressure: ");
    Serial.print(bme.readPressure());
    Serial.println(" Pa");

    Serial.print("Altitude: ");
    Serial.print(bme.readAltitude(sealevel));
    Serial.println(" m");

    Serial.print("Humidity: ");
    Serial.print(bme.readHumidity());
    Serial.println(" %");

    Serial.println();
    delay(1000);
}
