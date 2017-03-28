
#include <Wire.h>
#include <SparkFunLSM9DS1.h>

LSM9DS1 NineDoF;
#define MAG_ADDRESS	0x1E 
#define AG_ADDRESS 0x6B 

void setup() {  
  Serial.begin(9600);
  Serial.println("Starting 9DOF");
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
  Serial.println("Loop");
  printGyro();  
  printAccel(); 
  printMag();   
  Serial.println();  
  delay(250);
}

void printGyro(){ 
  NineDoF.readGyro();   
  Serial.print("G: ");    
  Serial.print(NineDoF.calcGyro(NineDoF.gx), 2);
  Serial.print(", ");
  Serial.print(NineDoF.calcGyro(NineDoF.gy), 2);
  Serial.print(", ");
  Serial.print(NineDoF.calcGyro(NineDoF.gz), 2);
  Serial.println(" deg/s");  
}

void printAccel(){
  NineDoF.readAccel();  
  Serial.print("A: ");
  Serial.print(NineDoF.calcAccel(NineDoF.ax), 2);
  Serial.print(", ");
  Serial.print(NineDoF.calcAccel(NineDoF.ay), 2);
  Serial.print(", ");
  Serial.print(NineDoF.calcAccel(NineDoF.az), 2);
  Serial.println(" g");
  
}

void printMag(){
  NineDoF.readMag();
  Serial.print("M: ");
  Serial.print(NineDoF.calcMag(NineDoF.mx), 2);
  Serial.print(", ");
  Serial.print(NineDoF.calcMag(NineDoF.my), 2);
  Serial.print(", ");
  Serial.print(NineDoF.calcMag(NineDoF.mz), 2);
  Serial.println(" gauss");
}

