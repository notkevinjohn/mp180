
void setup() {
  Serial.begin(9600);
  while(!Serial){}
  Serial.println("Light Sensor Starting");
}

void loop() {
  int light = readLightSensor(); 
  Serial.println(light);
  delay(1000);
}

int readLightSensor(){
  return analogRead(5);
}

