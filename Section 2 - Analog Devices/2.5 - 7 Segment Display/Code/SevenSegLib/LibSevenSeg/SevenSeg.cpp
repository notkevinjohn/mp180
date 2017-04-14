#include "Arduino.h"
#include "SevenSeg.h"

//display selectors
extern int d1 = 11;
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

int SevenSeg::d1(){
	return d1;
}
int SevenSeg::d2(){
	return d2;
}
int SevenSeg::d3(){
	return d3;
}
int SevenSeg::d4(){
	return d4;
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