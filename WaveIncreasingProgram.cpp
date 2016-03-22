#include "WaveIncreasingProgram.h"

WaveIncreasingProgram::WaveIncreasingProgram(int delay, int width, int freq, int increaseRateValue){

	this->delay = delay;

	this->freq = freq;
	this->width = width;

	this->increaseRateValue = increaseRateValue;
}

void WaveIncreasingProgram::onStart(Pulse *pulse){

	pulse->setWidth(width);
	pulse->setFreq(this->freq);

	pulse->setLedOffset(90);

	this->startDelay = this->delay;
	this->increaseRate = 1;

	this->up = false;
	this->increase = false;
}

//void WaveIncreasingProgram::onStart(Pulse *pulse[]){

//	for (int i = CHANNELS - 1; i >= 0; i--){

//		pulse[i]->setWidth(width);
//		pulse[i]->setFreq(this->freq);

//		pulse[i]->setLedOffset(90);
//	}

//	this->startDelay = this->delay;
//	this->increaseRate = 1;

//	this->up = false;
//	this->increase = false;
//}

bool WaveIncreasingProgram::onTick(Pulse *pulse, long delta){

	if (delta > this->delay){

		if (this->up == true){
			
			pulse->setWidth(pulse->getWidth() + 1);
		}else{

			pulse->setWidth(pulse->getWidth() - 1);
		}

		if (pulse->getWidth() >= 280){

			this->programCounter++;
			this->up = false;
		}else if (pulse->getWidth() <= 90){

			this->programCounter++;
			this->up = true;
		}

		if (this->programCounter >= 2){
			
			if (this->increase == true){

				this->delay += this->increaseRateValue;
			}else{

				this->delay -= this->increaseRateValue;
			}

			this->programCounter = 0;
		}

		if (this->delay < (this->increaseRateValue + 10)){

			this->increase = true;
		}else if (this->delay > this->startDelay){

			this->increase = false;
		}

		return true;
	}

	return false;
}

//bool WaveIncreasingProgram::onTick(Pulse *pulse[], long delta){

//	if (delta > this->delay){

//		for (int i = CHANNELS - 1; i >= 0; i--){

//			if (this->up == true){

//				pulse[i]->setWidth(pulse[i]->getWidth() + 1);
//			}
//			else{

//				pulse[i]->setWidth(pulse[i]->getWidth() - 1);
//			}

//			if (pulse[i]->getWidth() >= 280){

//				this->programCounter++;
//				this->up = false;
//			}
//			else if (pulse[i]->getWidth() <= 90){

//				this->programCounter++;
//				this->up = true;
//			}

//			if (this->programCounter >= 2){

//				if (this->increase == true){

//					this->delay += this->increaseRateValue;
//				}
//				else{

//					this->delay -= this->increaseRateValue;
//				}

//				this->programCounter = 0;
//			}

//			if (this->delay < (this->increaseRateValue + 10)){

//				this->increase = true;
//			}
//			else if (this->delay > this->startDelay){

//				this->increase = false;
//			}

//			return true;
//		}
			
//	}

//	return false;
//}