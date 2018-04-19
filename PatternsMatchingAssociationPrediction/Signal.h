#pragma once
class Signal
{
	/* The variables used in this class. */
	int frequency; // Integer value that represents incoming frequency.
public:

	/* The function signatures for this class. */
	Signal();
	Signal(int);
	~Signal();
	void setFrequency(int);
	int getFrequency();
};

