#pragma once

#include "Program.h"

class BurstProgram : public Program{

public:
	BurstProgram(int width, int freq, long stepOne, long stepTwo);

	void onStart(Pulse *pulse);
	bool onTick(Pulse *pulse, long delta);
   
private:
	bool doOutput;

	long stepOne;
	long stepTwo;

	int width;
	int freq;
};

