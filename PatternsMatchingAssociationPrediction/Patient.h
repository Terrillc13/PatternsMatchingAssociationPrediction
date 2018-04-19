#pragma once
#include "Issue.h"
#include "Signal.h"
#include <string>
#include <iostream>
using namespace std;
class Patient
{
	/* The variables used in this class. */
	int stats[2][5]; // The Patient stats representing valid ranges.
	bool isAbnormal[5]; // Boolean values that show if signals are abnormal or not.
public:

	/* The function signatures for this class. */
	Patient();
	Patient(int stats[][5]);
	~Patient();
	void setStats(int stats[][5]);
	int getStats(int, int);
	void checkRanges(Signal signals[]);
	string matchPattern(Issue issues[]);
};

