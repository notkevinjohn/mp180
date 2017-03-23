int lightSensorPin = 5; 

void setup() {
  Serial.begin(9600);
  while(!Serial){}
  Serial.println("Light Sensor Starting");

}

void loop() {
  int light = analogRead(lightSensorPin); 
  Serial.println(light);
  delay(1000);

}
