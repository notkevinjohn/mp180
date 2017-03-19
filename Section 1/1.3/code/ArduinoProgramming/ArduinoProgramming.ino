
void setup() {   
  Serial.begin(9600); 
}

void loop() { 
 int num1 = random(0,10); 
 int num2 = random(0,10); 
 int sum = AddInts(num1, num2); 
 String message = String(num1) + "+" + String(num2) + "=" + String(sum);  
 Serial.println(message); 
 delay(1000); 
}

int AddInts (int num1, int num2){
  return num1 + num2;
}

