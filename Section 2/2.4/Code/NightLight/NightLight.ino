
void setup() { 
  Serial.begin(9600);
  while(!Serial){}
  Serial.println("Night Light Starting");
}

void loop() {
  int light = readLightSensor(); 
  //Serial.println(light);
  if(light>150){
    ledOff();
  }
  else
  {
    ledOn();
  }
  //delay(1000);
}

int readLightSensor(){
  return analogRead(5);
}
int ledPin = 13;
void ledOn(){
  digitalWrite(ledPin, HIGH);
}
void ledOff(){
  digitalWrite(ledPin, LOW);
}

