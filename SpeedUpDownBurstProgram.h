#pragma once
#include "Program.h"

class SpeedUpDownBurstProgram : public Program{

public:
	void onStart(Pulse *pulse);
	//void onStart(Pulse *pulse[]);

	bool onTick(Pulse *pulse, long delta);
	//bool onTick(Pulse *pulse[], long delta);

private:
	void shouldIncTimer(long delta);

	bool doOutput;
	bool increase;
	bool hold;

	int mp;
	int mpCounter;

	long tempDelta;

	long outPutIncreaseRateValue;
	long noOutPutIncreaseRateValue;
	long outputWidth;
	long noOutputWidth;
};

