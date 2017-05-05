#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

int _SCK  = 13;
int _MISO = 12;
int _MOSI = 11;
int _CS = 9;
float sealevel = 1013.25;

Adafruit_BME280 bme(_CS);

void setup() {
    Serial.begin(9600);
    Serial.println("Starting BME280"); 
    
    if (!bme.begin()) {
        Serial.println("Device Failed or Not Present");
        while (1);    
    }  
    delay(1000); 
}

void loop() { 
    Serial.print("Temperature: ");
    Serial.print(bme.readTemperature());
    Serial.println(" C");

    Serial.print("Pressure: ");
    Serial.print(bme.readPressure() / 100.0F);
    Serial.println(" hPa");

    Serial.print("Altitude: ");
    Serial.print(bme.readAltitude(sealevel));
    Serial.println(" m");

    Serial.print("Humidity: ");
    Serial.print(bme.readHumidity());
    Serial.println(" %");

    Serial.println();
    delay(1000);
}
