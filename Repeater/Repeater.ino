
void setup() {  
  Serial.begin(9600);
  while (!Serial) {}
  Serial.println("Staring Serial Repeater");
}

void loop() { 
  if(Serial.available() > 0 ){   
    String message = serialMessage();
    /*enter code that prints message to serial port*/
  }
}

String serialMessage(){
  String message = "";
   while(Serial.available() > 0) {
      message += char(Serial.read());
      delay(5);
    }
    return message;
}



