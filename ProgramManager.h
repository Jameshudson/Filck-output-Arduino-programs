#pragma once

#include "Program.h"
#include "Pulse.h"

class ProgramManager{

public:
	ProgramManager();

	void addProgram(Program *program);

	void run(Pulse *pulse);

	void changeProgram(int index, Pulse *pulse);
	//void changeProgram(int index, Pulse *pulse[]);

	int size();

	void setNoProgram(int freq, int width);

	int getProgramSelected();

private:
	Program* currentlyRunning;

	Program *programs[6];
	int programCounter;

	int noProgramWidth;
	int noProgramFreq;

	bool noProgramSelected;

	long programStartTime;
	long programEndTime;
	long programDelta;
};