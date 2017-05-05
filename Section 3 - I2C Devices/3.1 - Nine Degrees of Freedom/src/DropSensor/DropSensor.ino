
#include <Wire.h>
#include <SparkFunLSM9DS1.h>

LSM9DS1 NineDoF;
#define MAG_ADDRESS	0x1E 
#define AG_ADDRESS 0x6B 

void setup() {  
  Serial.begin(9600);
  Serial.println("Starting Drop Sensor");
  pinMode(13, OUTPUT);
  NineDoF.settings.device.commInterface = IMU_MODE_I2C;
  NineDoF.settings.device.mAddress = MAG_ADDRESS;
  NineDoF.settings.device.agAddress = AG_ADDRESS;
  if (!NineDoF.begin())
  {
    Serial.println("Failed to communicate with 9DOF.");
    while (1);
  }
}

void loop(){
  NineDoF.readAccel();  
  float zAccel = NineDoF.calcAccel(NineDoF.az);
  if(zAccel < 0.50){
    Serial.println("Drop Detected!");
    lightOn();
  }
 
}

void lightOn()
{
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
}
