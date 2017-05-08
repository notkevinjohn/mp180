
#include <Wire.h>
#include <SparkFunLSM9DS1.h>

LSM9DS1 NineDoF;
int MAG_ADDRESS = 0x1E;
int AG_ADDRESS = 0x6B;

void setup() {  
  Serial.begin(9600);
  Serial.println("Initializing 9DoF...");
  NineDoF.settings.device.commInterface = IMU_MODE_I2C;
  NineDoF.settings.device.mAddress = MAG_ADDRESS;
  NineDoF.settings.device.agAddress = AG_ADDRESS;
  if (!NineDoF.begin())
  {
    Serial.println("9DoF Failed or Not Present");
    while (1);
  }
   Serial.println("...9DoF Initialized");
   Serial.println();
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
  Serial.print(gyroX);
  Serial.print(", ");
  Serial.print(gyroY);
  Serial.print(", ");
  Serial.print(gyroZ);
  Serial.println(" deg/s");  
}

void printAccel(){
  NineDoF.readAccel();  
  double accelX = NineDoF.calcAccel(NineDoF.ax);
  double accelY = NineDoF.calcAccel(NineDoF.ay);
  double accelZ = NineDoF.calcAccel(NineDoF.az);
  
  Serial.print("A: ");
  Serial.print(accelX);
  Serial.print(", ");
  Serial.print(accelY);
  Serial.print(", ");
  Serial.print(accelZ);
  Serial.println(" g");
  
}

void printMag(){
  NineDoF.readMag();
  double magX = NineDoF.calcMag(NineDoF.mx);
  double magY = NineDoF.calcMag(NineDoF.my);
  double magZ = NineDoF.calcMag(NineDoF.mz);
  
  Serial.print("M: ");
  Serial.print(magX);
  Serial.print(", ");
  Serial.print(magY);
  Serial.print(", ");
  Serial.print(magZ);
  Serial.println(" gauss");
}

