#pragma once
#include "Program.h"

class SpeedUpBurstProgram : public Program{

public:
	SpeedUpBurstProgram(int width, long freq, long counter, long outputTime, long noOutputTime);

	void onStart(Pulse *pulse);
	//void onStart(Pulse *pulse[]);

	bool onTick(Pulse *pulse, long delta);
	//bool onTick(Pulse *pulse[], long delta);

private:
	void shouldIncTimer(long delta);

	bool doOutput;
	bool increase;
	bool hold;

	int width;
	int freq;

	int mp;
	int mpCounter;

	long tempDelta;

	long outPutIncreaseRateValue;
	long noOutPutIncreaseRateValue;
	long outputWidth;
	long noOutputWidth;
};