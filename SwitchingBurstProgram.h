#pragma once

#include "Program.h"

class SwitchingBurstProgram : public Program{

public:

	SwitchingBurstProgram(int width, long nOffastOutput, int nOfslowOuput);
	
	void virtual onStart(Pulse *pulse);
	//void virtual onStart(Pulse *pulse[]);

	bool virtual onTick(Pulse *pulse, long delta);
	//bool virtual onTick(Pulse *pulse[], long delta);

private:
	bool doOutput;
	bool slowOutput;

	long nOfSlowOutput;
	long nOfFastOutput;

	int fastOutputTime;
	int slowOutputTime;

	int width;

	int outputCounter;
};

