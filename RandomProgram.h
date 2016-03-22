#pragma once
#include "Program.h"

class RandomProgram : public Program{

public:
	RandomProgram(int widthPercent[100], long freq);

	void onStart(Pulse *pulse);
	//void onStart(Pulse *pulse[]);

	bool onTick(Pulse *pulse, long delta);
	//bool onTick(Pulse *pulse[], long delta);

private:
	int widthPercent[100];
	long delay;
	int arrayCounter;
};

