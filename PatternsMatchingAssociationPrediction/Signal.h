#pragma once
/**
Signal Class is used to create a Signal object
that monitors signals being recieved. The Signal
object's isAbnormal Boolean value will be constantly
changed to represent if the Signals are producing
an abnormality or not.
Created By: Clayton D. Terrill and Ian Barney
April 14th, 2018.
*/
class Signal
{
public:
	/* The variables used in this class. */
	bool isAbnormal; // Boolean value that shows if signal is abnormal or not.

	/* The function signatures for this class. */
	Signal();
	Signal(bool);
	~Signal();
	void setIsAbnormal(bool);
	bool getIsAbnormal();
};

