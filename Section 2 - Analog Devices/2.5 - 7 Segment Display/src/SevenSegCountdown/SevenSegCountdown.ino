
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
  Serial.begin(9600);
  while(!Serial){}
  Serial.println("Starting 7 Segment");
  
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
  for(int i = 1200; i>0; i--){
   int ones  = i % 10;
   int tens  = i / 10 % 10;
   int hunds = i / 100 % 10;
   int thous = i / 1000 % 10; 

   for(int j =0; j<10; j++){
    numberToDisplay(ones,d4); 
    numberToDisplay(tens,d3);
    numberToDisplay(hunds,d2); 
    numberToDisplay(thous,d1);
   } 
   
  }
  while(true){}
}
void numberToDisplay(int num, int disp)
{
  digitalWrite(disp, LOW);
  displayNumber(num);
  delay(1);
  clearSegments();
  digitalWrite(disp, HIGH);
}
void displayNumber(int i)
{
  
  switch(i){
    case 0:
    zero();
    break;
    
    case 1:
    one();
    break;

    case 2:
    two();
    break;

    case 3:
    three();
    break;

    case 4:
    four();
    break;

    case 5:
    five();
    break;

    case 6:
    six();
    break;

    case 7:
    seven();
    break;

    case 8:
    eight();
    break;

    case 9:
    nine();
    break;
    
  }
}
void zero(){
   digitalWrite(A, HIGH); 
   digitalWrite(B, HIGH); 
   digitalWrite(C, HIGH);
   digitalWrite(D, HIGH);
   digitalWrite(E, HIGH);
   digitalWrite(F, HIGH);
}

void one(){
   digitalWrite(B, HIGH); 
   digitalWrite(C, HIGH); 
}

void two(){
   digitalWrite(A, HIGH); 
   digitalWrite(B, HIGH); 
   digitalWrite(G, HIGH); 
   digitalWrite(E, HIGH); 
   digitalWrite(D, HIGH); 
}

void three(){
   digitalWrite(A, HIGH); 
   digitalWrite(B, HIGH); 
   digitalWrite(G, HIGH); 
   digitalWrite(C, HIGH); 
   digitalWrite(D, HIGH);
}

void four(){
  digitalWrite(F, HIGH); 
  digitalWrite(B, HIGH); 
  digitalWrite(G, HIGH); 
  digitalWrite(C, HIGH); 
}

void five(){
  digitalWrite(A, HIGH); 
  digitalWrite(F, HIGH); 
  digitalWrite(G, HIGH); 
  digitalWrite(C, HIGH); 
  digitalWrite(D, HIGH); 
}

void six(){
  digitalWrite(A, HIGH); 
  digitalWrite(F, HIGH); 
  digitalWrite(G, HIGH); 
  digitalWrite(C, HIGH); 
  digitalWrite(D, HIGH); 
  digitalWrite(E, HIGH);
}

void seven(){
  digitalWrite(A, HIGH); 
  digitalWrite(B, HIGH); 
  digitalWrite(C, HIGH);  
}

void eight() {
  digitalWrite(A, HIGH); 
  digitalWrite(B, HIGH); 
  digitalWrite(G, HIGH); 
  digitalWrite(F, HIGH); 
  digitalWrite(C, HIGH); 
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
}

void nine(){
  digitalWrite(A, HIGH); 
  digitalWrite(B, HIGH); 
  digitalWrite(G, HIGH); 
  digitalWrite(F, HIGH); 
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
}

void clearSegments(){
  int lenSeg = sizeof(segments)/sizeof(int);  
  for(int i=0; i< lenSeg; i++){
    int pin = segments[i];       
    digitalWrite(pin, LOW); 
  }
}



