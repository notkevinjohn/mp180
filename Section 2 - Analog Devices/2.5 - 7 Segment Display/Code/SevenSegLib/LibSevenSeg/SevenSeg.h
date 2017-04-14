#include "Arduino.h"

class SevenSeg 
{

public:
	void numberToDisplay(int num, int disp);
	int d1();
	int d2();
	int d3();
	int d4();

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

