
//display selectors
int d1 = 11;
int d2 = 10;
int d3 = 9;
int d4 = 3;
int displays[] = {d1,d2,d3,d4};

//7 seg selectors
int A = 12;
int G = 13;
int D = 5;
int F = 8;
int E = 6;
int B = 7;
int C = 2;
int P = 4;
int segments[] = {A,G,D,F,E,B,C,P};


void setup() {  
  int lenDisp = sizeof(displays)/sizeof(int);  
  for(int i = 0; i< lenDisp; i++){
    int pin = displays[i];   
    pinMode(pin, OUTPUT);  
    digitalWrite(pin, HIGH); 
  }
  int lenSeg = sizeof(segments)/sizeof(int);  
  for(int i=0; i< lenSeg; i++){
    int pin = segments[i];   
    pinMode(pin, OUTPUT);   
    digitalWrite(pin, LOW); 
  }  
}

void loop() { 
 int lenSeg = sizeof(segments)/sizeof(int);  
  for(int i = 0; i<lenSeg; i++) {
    int seg = segments[i];  
    digitalWrite(seg, HIGH); 
    int lenDisp = sizeof(displays)/sizeof(int);  
    for(int j = 0; j< lenDisp; j++){
      int disp = displays[j];   
      digitalWrite(disp, LOW);         
      delay(250);      
      digitalWrite(disp, HIGH);
    }
     digitalWrite(seg, LOW); 
  }
}


