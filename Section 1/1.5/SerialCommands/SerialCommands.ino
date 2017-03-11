
void setup() {  
  Serial.begin(9600);
  while (!Serial) {}
  Serial.println("Staring Serial Command Interface");  
}

void loop() { 
  if(Serial.available() > 0 ){   
    String message = serialMessage();   
    parseMessage(message);
  }
}

String serialMessage(){
  String message = "";
   while(Serial.available() > 0) {
      message += char(Serial.read());
      delay(5);
    }  
    message.trim();
    return message;
}

void parseMessage(String message){
  if(message.equals("Marco")) { 
    Serial.println("Polo"); 
  }
  else { 
    Serial.println(message);
  }
}

