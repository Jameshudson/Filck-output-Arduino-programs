#include "BurstProgram.h"

BurstProgram::BurstProgram(int width, int freq, long stepOne, long stepTwo){

	this->stepOne = stepOne;
	this->stepTwo = stepTwo;

	this->freq = freq;
	this->width = width;
}

void BurstProgram::onStart(Pulse* pulse){

	pulse->setWidth(this->width);
	pulse->setFreq(this->freq);

	pulse->setLedOffset(0);

	doOutput = true;
}

bool BurstProgram::onTick(Pulse* pulse, long delta){

	if (doOutput){

		pulse->setWidth(280);

		if (delta >= this->stepOne){

			doOutput = false;
			return true;
		}
	}else{

		pulse->setWidth(0);

		if (delta >= this->stepTwo){

			doOutput = true;
			return true;
		}
	}

	return false;
}