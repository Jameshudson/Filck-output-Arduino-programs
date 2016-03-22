#pragma once

#ifndef Pulse_h
#define Pulse_h

#include "Arduino.h"

class Pulse{
public:
	Pulse(int pwn, int drive, int ledPin, int debugledPin, int maxWidth);

	void setFreq(int freq);
	void setWidth(int width);
	void setIntensity(int );
	void setLedOffset(int offset);
	void setMaxWidth(int width);

	int getIntensity();
	int getWidth();
	int getMaxWidth();
	int getFreq();

	void outputDrive();
private: 
	int pwnPin;
	int drivePin;
	int ledPin;
	int debugledPin;

	int maxWidthOutput;

	int freq;
	int width;
	int intensity;

	int ledOffset;

	int startTime;
	int endTime;
	int delta;
	void(*ledHa)(void);
};

#endif