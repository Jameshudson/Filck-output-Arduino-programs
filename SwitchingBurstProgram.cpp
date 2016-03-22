#include "SwitchingBurstProgram.h"


SwitchingBurstProgram::SwitchingBurstProgram(int width, long nOffastOutput, int nOfslowOuput){

	this->width = width;

	//setting the number of off and ons the slow and fast output should be.
	this->nOfSlowOutput = nOfslowOuput;
	this->nOfFastOutput = nOffastOutput;
}

void SwitchingBurstProgram::onStart(Pulse *pulse){

	//setting the pulse setting
	pulse->setWidth(this->width);
	pulse->setLedOffset(0);

	//set the program counter to 0
	outputCounter = 0;

	doOutput = true;
	slowOutput = true;
}

bool SwitchingBurstProgram::onTick(Pulse *pulse, long delta){

	if (doOutput){//do output

		pulse->setWidth(280);
		pulse->setFreq(20000);

		if (slowOutput == true && delta >= 1500000){//slow

			outputCounter++;

			doOutput = false;
			return true;
		}else if (slowOutput == false && delta >= 250000){//fast

			outputCounter++;

			doOutput = false;
			return true;
		}
	}else{//no not do output

		pulse->setWidth(0);
		pulse->setFreq(12500);

		if (slowOutput == true && delta >= 500000){//slow

			outputCounter++;

			doOutput = true;
			return true;
		}else if (slowOutput == false && delta >= 100000){//fast

			outputCounter++;

			doOutput = true;
			return true;
		}
	}//end of output

	//check to see if the number of output have hit the limt.
	if (slowOutput == true && outputCounter >= nOfSlowOutput){//slow

		slowOutput = false;
		outputCounter = 0;
	}else if (slowOutput == false && outputCounter >= nOfFastOutput){//fast

		slowOutput = true;
		outputCounter = 0;
	}//end of counter check.

	return false;
}
