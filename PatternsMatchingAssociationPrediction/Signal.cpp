/**
Signal Class is used to create a Signal object
that monitors signals being recieved. The Signal
object's isAbnormal Boolean value will be constantly
changed to represent if the Signals are producing
an abnormality or not.
Created By: Clayton D. Terrill and Ian Barney
April 14th, 2018.
*/

#include "stdafx.h"
#include "Signal.h"
#include <string>
using namespace std;

/**
Function: Signal
Default Constructor of the Signal.
Initializes the isAbnormal to be NULL.
*/
Signal::Signal()
{
	this->isAbnormal = false; // It is unknown if the signal is abnormal or not.
}

/**
Function: Signal
Constructor for when a value has been designated during Signal object creation.
Initializes the isAbnormal to be NULL.
@param isAbnormalTemp - Boolean value to set isAbnormal with.
*/
Signal::Signal(bool isAbnormalTemp)
{
	this->isAbnormal = isAbnormalTemp; // A value has been designated during object creation.
}

/**
Function: ~Signal
Default Destructor that deletes the Signal. Prevents Memory Leak.
*/
Signal::~Signal()
{
	//delete this->isAbnormal) //Deletes the pointer.
}

/**
Function: setIsAbnormal
Sets the isAbnormal variable with a boolean value.
@param isAbnormalTemp - Boolean value to set isAbnormal with.
*/
void Signal::setIsAbnormal(bool isAbnormalTemp)
{
	this->isAbnormal = isAbnormalTemp;
}

/**
Function: getIsAbnormal
Returns whether a signal is abnormal or not.
@return isAbnormal - Boolean value that shows if signal is abnormal or not.
*/
bool Signal::getIsAbnormal()
{
	return this->isAbnormal;
}