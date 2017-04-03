
//display selectors
int d1 = 11;
int d2 = 10;
int d3 = 9;
int d4 = 8;

//7 seg selectors
int F = 12;
int A = 13;
int E = 7;
int D = 6;
int P = 5;
int C = 4;
int G = 3;

int pins[] = {d1,d2,d3,d4,F,A,E,D,P,C,G};

void setup() { 
  Serial.begin(9600);
  while(!Serial){}
  Serial.println("Starting 7 Segment");  
   for(int i = 0; i< sizeof(pins); i++){
    int pin = pins[i];
    if(pin != 0){
      Serial.println(pin);
    }
  }
}

void loop() { 
}

