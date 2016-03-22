#pragma once

#include "Arduino.h"
#include "Pulse.h"

class Program{

public:

	void virtual onStart(Pulse *pulse) = 0;
	//void virtual onStart(Pulse *pulse[]) = 0;

	bool virtual onTick(Pulse *pulse, long delta) = 0;
	//bool virtual onTick(Pulse *pulse[], long delta) = 0;
};


