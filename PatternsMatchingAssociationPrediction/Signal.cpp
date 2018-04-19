/**
Signal Class is used to create a Signal object
that monitors signals being recieved. The Signal
object's Integer value will be constantly
changed to represent if the Signals frequency.
Created By: Clayton D. Terrill and Ian Barney
April 10th, 2018.
*/

#include "stdafx.h"
#include "Signal.h"

/**
Function: Signal
Default Constructor of the Signal.
Initializes the frequency to be 0.
*/
Signal::Signal()
{
	this->frequency = 0; // Assume 0.
}

/**
Function: Signal
Constructor for when a value has been designated during Signal object creation.
Sets the frequency.
@param isAbnormalTemp - Boolean value to set isAbnormal with.
*/
Signal::Signal(int frequency)
{
	// Calling set function allows for only one method to need modified.
	this->setFrequency(frequency);
}

/**
Function: ~Signal
Default Destructor that deletes the Signal. Prevents Memory Leak.
*/
Signal::~Signal()
{
}

/**
Function: setFrequency
Sets the frequency variable with an Integer value.
@param frequency - Integer value to set frequency with.
*/
void Signal::setFrequency(int frequency)
{
	this->frequency = frequency;
}

/**
Function: getFrequency
Returns the frequency of the Signal.
@return frequency - Integer value to for the frequency.
*/
int Signal::getFrequency()
{
	return frequency;
}
