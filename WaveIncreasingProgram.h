#pragma once

#include "Program.h"
#include "Math.h"

class WaveIncreasingProgram : public Program{

public:
	WaveIncreasingProgram(int delay, int width, int freq, int increaseRateValue);

	void onStart(Pulse *pulse);
	//void onStart(Pulse *pulse[]);

	bool onTick(Pulse *pulse, long delta);
	//bool onTick(Pulse *pulse[], long delta);

private:
	bool up;
	int delay;
	int startDelay;
	int programCounter;

	int width;
	int freq;

	float increaseRateValue;
	double increaseRate;
	bool increase;
};

