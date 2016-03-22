#include "RandomProgram.h"


RandomProgram::RandomProgram(int tempWidthPercent[100], long freq){

	for (int i = 100; i > 0; i--){

		this->widthPercent[i] = tempWidthPercent[i];
	}

	this->delay = freq;
}

void RandomProgram::onStart(Pulse *pulse){

	this->arrayCounter = 0;
}

bool RandomProgram::onTick(Pulse *pulse, long delta){

	if (delta >= this->delay){

		if (this->arrayCounter > 100){

			this->arrayCounter = 0;
		}

		pulse->setWidth(this->widthPercent[this->arrayCounter++]);
		return true;
	}

	return false;
}