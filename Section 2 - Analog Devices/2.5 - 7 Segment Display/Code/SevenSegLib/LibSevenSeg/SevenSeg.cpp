#include "Arduino.h"
#include "SevenSeg.h"

//display selectors
int d1,d2,d3,d4;
int displays[]={d1,d2,d3,d4};

//7 seg selectors
int A,G,D,F,E,B,C,P;
int segments[]={A,G,D,F,E,B,C,P};

void SevenSeg::setup()
{
 	//discreet display selectors
 	d1 = 11;
 	displays[0] = d1;
	d2 = 10;
	displays[1] = d2;
	d3 = 9;
	displays[2] = d3;
	d4 = 3;
	displays[3] = d4;

	//discreet segment selectors
	A = 12;
	segments[0] = A;
	G = 13;
	segments[1] = G;
	D = 5;
	segments[2] = D;
	F = 8;
	segments[3] = F;
	E = 6;
	segments[4] = E;
	B = 7;
	segments[5] = B;
	C = 2;
	segments[6] = C;
	P = 4;
	segments[7] = P;

	
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

void SevenSeg::display(int num, int time = 10)
{
   int ones  = num % 10;
   int tens  = num / 10 % 10;
   int hunds = num / 100 % 10;
   int thous = num / 1000 % 10; 

   	for(int j = 0; j<time; j++) {
	    numberToDisplay(ones,d4); 
	    numberToDisplay(tens,d3);
	    numberToDisplay(hunds,d2); 
	    numberToDisplay(thous,d1);
   	}
}

void SevenSeg::numberToDisplay(int num, int disp)
{ 
  digitalWrite(disp, LOW);
  displayNumber(num);
  delay(1);
  clearSegments();
  digitalWrite(disp, HIGH);
}

void SevenSeg::displayNumber(int i)
{  
 
  switch(i) {
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


void SevenSeg::zero(){
   digitalWrite(A, HIGH); 
   digitalWrite(B, HIGH); 
   digitalWrite(C, HIGH);
   digitalWrite(D, HIGH);
   digitalWrite(E, HIGH);
   digitalWrite(F, HIGH);
}

void SevenSeg::one(){  
   digitalWrite(B, HIGH); 
   digitalWrite(C, HIGH); 
}

void SevenSeg::two(){
   digitalWrite(A, HIGH); 
   digitalWrite(B, HIGH); 
   digitalWrite(G, HIGH); 
   digitalWrite(E, HIGH); 
   digitalWrite(D, HIGH); 
}

void SevenSeg::three(){
   digitalWrite(A, HIGH); 
   digitalWrite(B, HIGH); 
   digitalWrite(G, HIGH); 
   digitalWrite(C, HIGH); 
   digitalWrite(D, HIGH);
}

void SevenSeg::four(){
  digitalWrite(F, HIGH); 
  digitalWrite(B, HIGH); 
  digitalWrite(G, HIGH); 
  digitalWrite(C, HIGH); 
}

void SevenSeg::five(){
  digitalWrite(A, HIGH); 
  digitalWrite(F, HIGH); 
  digitalWrite(G, HIGH); 
  digitalWrite(C, HIGH); 
  digitalWrite(D, HIGH); 
}

void SevenSeg::six(){
  digitalWrite(A, HIGH); 
  digitalWrite(F, HIGH); 
  digitalWrite(G, HIGH); 
  digitalWrite(C, HIGH); 
  digitalWrite(D, HIGH); 
  digitalWrite(E, HIGH);
}

void SevenSeg::seven(){
  digitalWrite(A, HIGH); 
  digitalWrite(B, HIGH); 
  digitalWrite(C, HIGH);  
}

void SevenSeg::eight() {
  digitalWrite(A, HIGH); 
  digitalWrite(B, HIGH); 
  digitalWrite(G, HIGH); 
  digitalWrite(F, HIGH); 
  digitalWrite(C, HIGH); 
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
}

void SevenSeg::nine(){
  digitalWrite(A, HIGH); 
  digitalWrite(B, HIGH); 
  digitalWrite(G, HIGH); 
  digitalWrite(F, HIGH); 
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
}

void SevenSeg::clearSegments(){
  int lenSeg = sizeof(segments)/sizeof(int);  
  for(int i=0; i< lenSeg; i++){
    int pin = segments[i];       
    digitalWrite(pin, LOW); 
  }
}