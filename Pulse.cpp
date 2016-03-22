#include "Pulse.h"

Pulse::Pulse(int pwnPin, int drivePin, int ledPin, int debugLEDpin, int maxWidth){

	this->pwnPin = pwnPin;
	this->drivePin = drivePin;
	this->ledPin = ledPin;

	this->debugledPin = debugLEDpin;

	pinMode(this->pwnPin, OUTPUT);
	pinMode(this->drivePin, OUTPUT);

	pinMode(this->debugledPin, OUTPUT);
	pinMode(this->ledPin, OUTPUT);

	this->maxWidthOutput = maxWidth;

	this->freq = 0;
	this->intensity = 0;
	this->width = 0;

	this->startTime = 0;
	this->endTime = 0;
	this->delta = 0;
}

void Pulse::setLedOffset(int offset){
	this->ledOffset = offset;
}

void Pulse::setFreq(int freq){

	if (freq >= 5000 && freq <= 25000){

		this->freq = freq;
	}
}

void Pulse::setIntensity(int intensity){
	this->intensity = intensity;
}

void Pulse::setWidth(int width){
	this->width = width;
}

int Pulse::getIntensity(){
	return this->intensity;
}

int Pulse::getWidth(){
	return this->width;
}

int Pulse::getMaxWidth(){
	return maxWidthOutput;
}

void Pulse::setMaxWidth(int width){
	this->maxWidthOutput;
}

int Pulse::getFreq(){
	return this->freq;
}


void Pulse::outputDrive(){

	digitalWrite(this->debugledPin, LOW);

	//checks to see if the width output is greater then 0
	if (this->width > 0 && this->width <= maxWidthOutput){

		digitalWrite(this->drivePin, HIGH);

		//stop the arduino for set amount of time (width)
		for (int x = this->width; x > 0; x--){
			__asm__("nop\n\t");
		}

		digitalWrite(this->drivePin, LOW);

		//Intensity 
		if (this->getIntensity() > 0){

			analogWrite(this->pwnPin, this->getIntensity());
		}else if (this->getIntensity() > 255){

			analogWrite(this->pwnPin, 255);
		}else{

			analogWrite(this->pwnPin, 0);
		}//end of intensity check
	}else{

		digitalWrite(this->debugledPin, HIGH);
	}//end of width check

	//LED
	if ((this->getWidth() - this->ledOffset) > 0){

		analogWrite(this->ledPin, (this->getWidth() - this->ledOffset));
	}else{

		analogWrite(this->ledPin, 0);
	}//end of led check
}