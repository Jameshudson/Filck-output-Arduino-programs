#include <TimerOne.h>

#include "Pulse.h"
#include "ProgramManager.h"

#include "Program.h"

#include "WaveProgram.h"
#include "WaveIncreasingProgram.h"
#include "BurstProgram.h"
#include "SwitchingBurstProgram.h"
#include "SpeedUpBurstProgram.h"
#include "SpeedUpDownBurstProgram.h"

#include "DevBoard.h"

//starting Channel 1 ouput
Pulse ch1(CHANNEL_1_PWN_PIN, CHANNEL_1_DRIVE_PIN, CHANNEL_1_LED_PIN, NO_PIN, CHANNEL_1_WIDTH);

//flick programs
ProgramManager programManager;

int selectedProgram = 0;
long oldFreq = 0;

void setup(){

	Serial.begin(115200);

	pinMode(POTENTIOMETER_PIN, INPUT);

	ch1.setFreq(CHANNEL_1_FREQUENCY);
	ch1.setWidth(CHANNEL_1_WIDTH);
	ch1.setIntensity(CHANNEL_1_INTENSITY);

	//setting the program manager settings
	programManager.setNoProgram(CHANNEL_1_FREQUENCY, CHANNEL_1_WIDTH);

	//adding programs to the Program manager
	programManager.addProgram(new WaveProgram(20000, 100, 12500));
	programManager.addProgram(new WaveIncreasingProgram(5000, 100, 15000, 100));

	programManager.addProgram(new BurstProgram(100, 20000, 1750000, 500000));
	programManager.addProgram(new SwitchingBurstProgram(100, 32, 13));
	programManager.addProgram(new SpeedUpBurstProgram(280, 15000, 10, 1750000, 500000));
	programManager.addProgram(new SpeedUpDownBurstProgram);

	//setting the program manager to 
	programManager.changeProgram(NO_PROGRAM, &ch1);

	Timer1.initialize(ch1.getFreq());
	oldFreq = ch1.getFreq();
	Timer1.attachInterrupt(timerCallback);
}

void loop(){

	programManager.run(&ch1);

	int potLevel = analogRead(POTENTIOMETER_PIN) / 4;
	ch1.setIntensity(potLevel);

	//for debugging ONLY!
	if (DEBUG){

		
	}//end of debugging code
}

//function for the Interrupt timer.
void timerCallback(){

	ch1.outputDrive();

	//check to see if the freq needs updating.
	if (ch1.getFreq() != oldFreq){

		Timer1.initialize(ch1.getFreq());
		oldFreq = ch1.getFreq();
		Timer1.attachInterrupt(timerCallback);
	}
}