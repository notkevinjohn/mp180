
#include <Wire.h>
#include <SparkFunLSM9DS1.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

LSM9DS1 NineDoF;
#define MAG_ADDRESS	0x1E 
#define AG_ADDRESS 0x6B 
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

double accelX;
double accelY;
double accelZ;
double accelMag;

void setup() {    
  init_9DOF();
  init_OLED();
}

void init_9DOF(){
  NineDoF.settings.device.commInterface = IMU_MODE_I2C;
  NineDoF.settings.device.mAddress = MAG_ADDRESS;
  NineDoF.settings.device.agAddress = AG_ADDRESS;  
  NineDoF.begin();  
  NineDoF.setAccelScale(2);
}

void init_OLED(){
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
  delay(1000);
}

void loop(){  
  getAccel();
  printAccel(); 
  if(checkTilt()) tilt();
  delay(1000);
  display.clearDisplay();
  display.setCursor(0,0); 
}

void getAccel(){
  NineDoF.readAccel();    
  accelX = NineDoF.calcAccel(NineDoF.ax);
  accelY = NineDoF.calcAccel(NineDoF.ay);
  accelZ = NineDoF.calcAccel(NineDoF.az); 
  accelMag = pow(pow(accelX,2)+pow(accelY,2)+pow(accelZ,2),2);
}

void printAccel(){   
  display.print("A: ");
  display.print(NineDoF.calcAccel(NineDoF.ax), 2);
  display.print(", ");
  display.print(NineDoF.calcAccel(NineDoF.ay), 2);
  display.print(", ");
  display.println(NineDoF.calcAccel(NineDoF.az), 2);  
  display.print("|A|: ");
  display.println(accelMag);
  display.display();
}

bool checkTilt(){
  if((abs(accelX) > 0.2 || abs(accelY) > 0.2) && accelMag < 1.10) 
  {
    return true;  
  }
  return false;
}

void tilt(){
    display.clearDisplay();
    display.setTextSize(2);
    display.print("TILT!");
    display.display();
    delay(10000);
    setup();
}

