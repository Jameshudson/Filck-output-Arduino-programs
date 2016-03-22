#include "SpeedUpDownBurstProgram.h"

void SpeedUpDownBurstProgram::onStart(Pulse *pulse){

	pulse->setWidth(269);
	pulse->setFreq(15000);
	pulse->setLedOffset(0);

	mpCounter = 1;
	mp = 10;

	doOutput = false;

	increase = false;

	hold = false;

	outputWidth = 1750000;
	noOutputWidth = 500000;

	outPutIncreaseRateValue = (1750000 / mp);
	noOutPutIncreaseRateValue = (500000 / mp);
}

bool SpeedUpDownBurstProgram::onTick(Pulse *pulse, long delta){

	if (mpCounter >= mp){

		increase = !increase;
		mpCounter = 0;
	}

	if (doOutput){

		pulse->setWidth(280);

		if (delta > outputWidth){

			doOutput = false;

			this->shouldIncTimer(delta);

			return true;
		}
	}else {

		pulse->setWidth(0);

		if (delta > noOutputWidth){

			doOutput = true;

			this->shouldIncTimer(delta);

			return true;
		}
	}

	return false;
}

void SpeedUpDownBurstProgram::shouldIncTimer(long delta){

	tempDelta += delta;

	if (tempDelta > 1000000){

		//Serial.print("outputWidth");
		//Serial.println(outputWidth);

		//Serial.print("noOutputWidth");
		//Serial.println(noOutputWidth);

		mpCounter++;

		if (increase == false){

			outputWidth -= outPutIncreaseRateValue;
			noOutputWidth -= noOutPutIncreaseRateValue;
		}else{

			outputWidth += outPutIncreaseRateValue;
			noOutputWidth += noOutPutIncreaseRateValue;
		}

		tempDelta = 0;
	}
}