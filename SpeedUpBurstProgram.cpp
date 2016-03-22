#include "SpeedUpBurstProgram.h"

SpeedUpBurstProgram::SpeedUpBurstProgram(int width, long freq, long counter, long outputTime, long noOutputTime){

	this->mp = counter;

	this->width = width;
	this->freq = freq;

	this->outputWidth = outputTime;
	this->noOutputWidth = noOutputTime;

	outPutIncreaseRateValue = (outputWidth / mp);
	noOutPutIncreaseRateValue = (noOutputWidth / mp);
}

void SpeedUpBurstProgram::onStart(Pulse *pulse){

	//setting the pulse settings
	pulse->setWidth(this->width);
	pulse->setFreq(this->freq);

	pulse->setLedOffset(0);

	mpCounter = 1;

	doOutput = false;

	increase = false;

	hold = false;
}

bool SpeedUpBurstProgram::onTick(Pulse *pulse, long delta){

	//checking that the number of ouput hasn't gone pass the max allowed
	if (mpCounter >= mp){

		hold = true;

		if (delta > 2000000){

			mpCounter = 0;
			hold = false;

			return true;
		}
		
		pulse->setWidth(280);

		outputWidth = 1750000;
		noOutputWidth = 500000;
	}

	if (doOutput && hold == false){

		pulse->setWidth(280);

		if (delta > outputWidth){

			doOutput = false;

			this->shouldIncTimer(delta);

			return true;
		}
	}else if (hold == false){

		pulse->setWidth(0);

		if (delta > noOutputWidth){

			doOutput = true;

			this->shouldIncTimer(delta);

			return true;
		}
	}

	return false;
}

void SpeedUpBurstProgram::shouldIncTimer(long delta){

	tempDelta += delta;

	if (tempDelta > 1000000){

		mpCounter++;

		outputWidth -= outPutIncreaseRateValue;
		noOutputWidth -= noOutPutIncreaseRateValue;

		tempDelta = 0;
	}
}