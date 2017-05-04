
#include <Wire.h>
#include <SparkFunLSM9DS1.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

LSM9DS1 NineDoF;
#define MAG_ADDRESS	0x1E 
#define AG_ADDRESS 0x6B 

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

void setup() {    
  NineDoF.settings.device.commInterface = IMU_MODE_I2C;
  NineDoF.settings.device.mAddress = MAG_ADDRESS;
  NineDoF.settings.device.agAddress = AG_ADDRESS;  
  NineDoF.begin();  
  NineDoF.setAccelScale(16);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Starting 9DOF");
  display.println("Starting OLED");
  display.display();
  display.clearDisplay();
  display.setCursor(0,0);
}

void loop(){
  printGyro();  
  printAccel(); 
  printMag();   
  display.display();
  delay(1000);
  display.clearDisplay();
  display.setCursor(0,0); 
}

void printGyro(){ 
  NineDoF.readGyro();   
  display.print("G: ");    
  display.print(NineDoF.calcGyro(NineDoF.gx), 1);
  display.print(", ");
  display.print(NineDoF.calcGyro(NineDoF.gy), 1);
  display.print(", ");
  display.println(NineDoF.calcGyro(NineDoF.gz), 1);
}

void printAccel(){
  NineDoF.readAccel();   
  display.print("A: ");
  display.print(NineDoF.calcAccel(NineDoF.ax), 1);
  display.print(", ");
  display.print(NineDoF.calcAccel(NineDoF.ay), 1);
  display.print(", ");
  display.println(NineDoF.calcAccel(NineDoF.az), 1);  
}

void printMag(){
  NineDoF.readMag();
  display.print("M: ");
  display.print(NineDoF.calcMag(NineDoF.mx), 1);
  display.print(", ");
  display.print(NineDoF.calcMag(NineDoF.my), 1);
  display.print(", ");
  display.println(NineDoF.calcMag(NineDoF.mz), 1);
}

