
#include <Wire.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(0);

void setup() {    
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);   
  display.setTextColor(WHITE);
  display.display(); 
  delay(3000);
}

void loop(){
  int time = millis()/1000;
  display.setCursor(0,0);  
  display.clearDisplay();
  display.print("running for ");
  display.print(time);
  display.println(" sec");
  display.display();
  delay(1000);
}

