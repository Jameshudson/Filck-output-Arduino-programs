#include "WaveProgram.h"
#include "Program.h"

WaveProgram::WaveProgram(int delay, int width, int freq){
	this->delay = delay;

	this->width = width;
	this->freq = freq;
}

void WaveProgram::onStart(Pulse* pulse){

	pulse->setWidth(this->width);
	pulse->setFreq(this->freq);

	pulse->setLedOffset(90);

    this->up = false;
}

//void WaveProgram::onStart(Pulse* pulse[]){

//	for (int i = CHANNELS - 1; i >= 0; i--){

//		pulse[i]->setWidth(this->width);
//		pulse[i]->setFreq(this->freq);

//		pulse[i]->setLedOffset(90);
//	}

//	this->up = false;
//}

bool WaveProgram::onTick(Pulse* pulse, long delta){

	if (delta > this->delay){
  
		if(this->up == true){
   
			pulse->setWidth(pulse->getWidth() + 3);
		}else{
                  
			pulse->setWidth(pulse->getWidth() - 3);
		}
                
		if (pulse->getWidth() >= 280){
                  
			this->up = false;
		}else if (pulse->getWidth() <= 90){
                 
			this->up = true; 
		}
                
		return true;
	}

	return false;
}

//bool WaveProgram::onTick(Pulse* pulse[], long delta){
	
//	if (delta > this->delay){

//		for (int i = CHANNELS - 1; i >= 0; i--){

//			if (this->up == true){

//				pulse[i]->setWidth(pulse[i]->getWidth() + 3);
//			}
//			else{

//				pulse[i]->setWidth(pulse[i]->getWidth() - 3);
//			}

//			if (pulse[i]->getWidth() >= 280){

//				this->up = false;
//			}
//			else if (pulse[i]->getWidth() <= 90){

//				this->up = true;
//			}

//			return true;
//		}
//	}

//	return false;
//}