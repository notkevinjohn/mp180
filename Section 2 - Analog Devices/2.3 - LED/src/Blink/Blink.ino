void setup() {
  // put your setup code here, to run once:
}

void loop() {
  ledOn();
  delay(1000);
  ledOff();
  delay(1000);
}

int ledPin = 13;

void ledOn(){
  digitalWrite(ledPin, HIGH);
}
void ledOff(){
  digitalWrite(ledPin, LOW);
}

