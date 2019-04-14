
void setup() { }


void loop() { }

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
