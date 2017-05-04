
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
  printGyro();  
  printAccel(); 
  printMag();   
  Serial.println();  
  delay(500);
}

void printGyro(){ 
  NineDoF.readGyro(); 
  double gyroX = NineDoF.calcGyro(NineDoF.gx);
  double gyroY = NineDoF.calcGyro(NineDoF.gy);
  double gyroZ = NineDoF.calcGyro(NineDoF.gz);
       
  Serial.print("G: ");    
  Serial.print(gyroX, 2);
  Serial.print(", ");
  Serial.print(gyroY, 2);
  Serial.print(", ");
  Serial.print(gyroZ, 2);
  Serial.println(" deg/s");  
}

void printAccel(){
  NineDoF.readAccel();  
  double accelX = NineDoF.calcAccel(NineDoF.ax);
  double accelY = NineDoF.calcAccel(NineDoF.ay);
  double accelZ = NineDoF.calcAccel(NineDoF.az);
  
  Serial.print("A: ");
  Serial.print(accelX, 2);
  Serial.print(", ");
  Serial.print(accelY, 2);
  Serial.print(", ");
  Serial.print(accelZ, 2);
  Serial.println(" g");
  
}

void printMag(){
  NineDoF.readMag();
  double magX = NineDoF.calcMag(NineDoF.mx);
  double magY = NineDoF.calcMag(NineDoF.my);
  double magZ = NineDoF.calcMag(NineDoF.mz);
  
  Serial.print("M: ");
  Serial.print(magX, 2);
  Serial.print(", ");
  Serial.print(magY, 2);
  Serial.print(", ");
  Serial.print(magZ, 2);
  Serial.println(" gauss");
}

