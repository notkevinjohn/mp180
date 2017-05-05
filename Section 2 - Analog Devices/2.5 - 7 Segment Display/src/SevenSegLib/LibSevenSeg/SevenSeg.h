#include "Arduino.h"

class SevenSeg 
{

public:
	void setup();
	void display(int num, int time);
	void numberToDisplay(int num, int disp);
	int d1,d2,d3,d4;	
	int A,G,D,F,E,B,C,P;

private:
	void clearSegments();
	void displayNumber(int i);	
	void zero();
	void one();
	void two();
	void three();
	void four();
	void five();
	void six();
	void seven();
	void eight();
	void nine();
};

