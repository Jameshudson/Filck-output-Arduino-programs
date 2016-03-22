#include "ProgramManager.h"

#include "DevBoard.h"

ProgramManager::ProgramManager(){

	this->programCounter = 0;

	this->programStartTime = 0;
	this->programEndTime = 0;
	this->programDelta = 0;
}

void ProgramManager::addProgram(Program *program){

	if (this->programCounter < MAX_PROGRAM_SIZE){

		this->programs[this->programCounter++] = program;
	}
}

int ProgramManager::getProgramSelected(){
	return this->programCounter;
}

void ProgramManager::run(Pulse *pulse){

	if (noProgramSelected != true){

		this->programEndTime = this->programStartTime;
		this->programStartTime = micros();

		this->programDelta += (this->programStartTime - this->programEndTime);

		if (this->programCounter != NO_PROGRAM){

			if (this->currentlyRunning->onTick(pulse, this->programDelta) == true){

				this->programDelta = 0;
			}
		}
	}
}

void ProgramManager::changeProgram(int index, Pulse *pulse){

	if (index != NO_PROGRAM){

		if (index < MAX_PROGRAM_SIZE){

			this->currentlyRunning = this->programs[index];

			this->currentlyRunning->onStart(pulse);

			this->programDelta = 0;
			this->programStartTime = 0;
			this->programEndTime = 0;

			noProgramSelected = false;
		}else{

			noProgramSelected = true;

			pulse->setWidth(noProgramWidth);
			pulse->setFreq(noProgramFreq);
		}
	}else{

		noProgramSelected = true;

		pulse->setWidth(noProgramWidth);
		pulse->setFreq(noProgramFreq);
	}
}

//TODO complete this method
//void ProgramManager::changeProgram(int index, Pulse *pulse[]){

//	if (index != NO_PROGRAM){

//		if (index < MAX_PROGRAM_SIZE){

//			this->currentlyRunning = this->programs[index];

			//this->currentlyRunning->onStart(pulse[]);

//			this->programDelta = 0;
//			this->programStartTime = 0;
//			this->programEndTime = 0;

//			noProgramSelected = false;
//		}
//		else{

//			noProgramSelected = true;

//			for (int i = CHANNELS - 1; i >= 0; i--){

//				pulse[i]->setWidth(noProgramWidth);
//				pulse[i]->setFreq(noProgramFreq);
//			};
//		}
//	}else{

//		noProgramSelected = true;

//		for (int i = CHANNELS - 1; i >= 0; i--){
			
//			pulse[i]->setWidth(noProgramWidth);
//			pulse[i]->setFreq(noProgramFreq);
//		}
//	}
//}

void ProgramManager::setNoProgram(int freq, int width){

	this->noProgramFreq = freq;
	this->noProgramWidth = width;
}

int ProgramManager::size(){
	return MAX_PROGRAM_SIZE;
}