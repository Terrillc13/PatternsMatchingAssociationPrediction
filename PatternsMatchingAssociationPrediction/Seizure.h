#pragma once
#include <string> // Needed in header for the String variable.
#include "Issue.h" // Needed in header for the Issue object.
#include "Signal.h" // Needed in header for the Signal object.
using namespace std; // Needed in header for the String variable.

/**
Seizure Class is used as a control class
that compares the Signal objects with the
Issue object patterns and determines if there
is a problem being outlined by the signals.
Created By: Clayton D. Terrill and Ian Barney
April 14th, 2018.
*/
class Seizure
{
public:

	/* The function signatures for this class. */
	Seizure();
	~Seizure();
	string checkForSeizure(Signal*, Issue*);
};

