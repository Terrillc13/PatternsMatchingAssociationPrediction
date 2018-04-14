#pragma once
/**
Signal Class is used to create a Tree with the organization of it dependent on it's key.
The value of the node is associated with this key.
This class uses utility functions from SignalNode.
Created By: Clayton D. Terrill
March 22nd, 2017.
*/
class Signal
{
public:
	/*The variables used in this class.*/
	bool isAbnormal; // Boolean value that shows if signal is abnormal or not.

					 /*The function signatures for this class.*/
	Signal();
	Signal(bool);
	~Signal();
	void setIsAbnormal(bool);
	bool getIsAbnormal();
};

