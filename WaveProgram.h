#pragma once

#include "Program.h"

class WaveProgram : public Program{

public:
	WaveProgram(int delay, int width, int freq);

	void onStart(Pulse *pulse);
	//void onStart(Pulse *pulse[]);

	bool onTick(Pulse *pulse, long delta);
	//bool onTick(Pulse *pulse[], long delta);
  
private:
	bool up;
	int delay;

	int width;
	int freq;
};


