void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(calibrateSensor(readTempSensor()));
  delay(1000);
}

int readTempSensor(){
  int sensorValue = analogRead(A3);
  return sensorValue;
}

float calibrateSensor(int raw){
  float y1 = 13; //cold deg C
  float y2 = 55; //hot deg C
  float x1 = 211; //cold adu
  float x2 = 372; //hot adu
  
  float m = (y2-y1)/(x2-x1);
  float b = y1 - m* x1;
  return raw*m+b;
}

