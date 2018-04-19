/**
Patient Class is used to create an Patient object
that represents a Patient. The Patient will store
the normal ranges for each signal as stats. These
stats are compared to the signal values and determines
if the signals or abnormal or not. Abnormalities are
stored in an array. The abnormal array is then compared
with Issues to see if the abnormal signals match an
Issue pattern that denotes a seizure.
Created By: Clayton D. Terrill and Ian Barney
April 10th, 2018.
*/

#include "stdafx.h"
#include "Patient.h"

/**
Function: Patient
Default Constructor of the Patient.
Initializes the Patient stats to be all 0.
Initializes the isAbnormal array to be all false.
*/
Patient::Patient()
{
	for (int i = 0; i < 5; i++) {
		this->stats[0][i] = 0;
		this->stats[1][i] = 0;
		isAbnormal[i] = false;
	}
}

/**
Function: Patient
Constructor for when attibutes are also passed
in during the Patient's creation.
Sets the Patient stats array.
Sets the isAbnormal array all to false.
@param stats - The array of provided stats.
*/
Patient::Patient(int stats[][5])
{
	for (int i = 0; i < 5; i++) {
		// Calling set function allows for only one method to need modified.
		this->setStats(stats);
		isAbnormal[i] = false;
	}
}

/**
Function: ~Patient
Default Destructor that deletes the Patient. Prevents Memory Leak.
*/
Patient::~Patient()
{
}

/**
Function: setStats
Sets the Patient stats array with the provided stats.
@param stats - The array of provided stats.
*/
void Patient::setStats(int stats[][5])
{
	for (int i = 0; i <= sizeof(stats); i++) {
		// Make sure there are valid ranges before setting.
		if (stats[0][i] <= stats[1][i])
		{
			this->stats[0][i] = stats[0][i];
			this->stats[1][i] = stats[1][i];
		}
		else
		{
			cout << "Signal " << i + 1 << " has an invalid range: " << stats[0][i] << " to " << stats[1][i] << endl;
			cout << "Please enter a valid range." << endl;
		}
	}
}

int Patient::getStats(int row, int col)
{
	return stats[row][col];
}

/**
Function: checkRanges
Checks to see if the Signal frequencies are within the Patient ranges.
@param issues - The Issue array to be compared with.
*/
void Patient::checkRanges(Signal signals[]) {
	for (int i = 0; i <= sizeof(signals); i++) {
		if (signals[i].getFrequency() < stats[0][i] || signals[i].getFrequency() > stats[1][i]) {
			isAbnormal[i] = true;
			cout << "		Signal " << i + 1 << ": " << signals[i].getFrequency() << "	- Abnormal - Out of Range" << endl;
		}
		else {
			isAbnormal[i] = false;
			cout << "		Signal " << i + 1 << ": " << signals[i].getFrequency() << "	- Normal - Within Range" << endl;
		}
	}
}

/**
Function: matchPattern
Compares the Signals in the Signal array with the abnormal pattern.
@param issues - The Issue array to be compared with.
*/
string Patient::matchPattern(Issue issues[])
{
	bool* patternTemp; // The current issue pattern array being observed.
	bool patternMatches; // Flag for whether an issue pattern matches the signals or not.

						 // Iterate through the issues and check their patterns.
	for (int i = 0; i < sizeof(isAbnormal) - 1; i++)
	{
		patternMatches = true; // Assume that the pattern matches.
		patternTemp = issues[i].getPattern(); // Set the current issue pattern array being observed.

											  // Check each signal with the current issue pattern.
		for (int j = 0; j <= sizeof(patternTemp); j++)
		{
			if (patternTemp[j] != isAbnormal[j])
			{
				// There was a discrepency between the issue pattern and a signal.
				patternMatches = false; // The pattern does not correspond with the signals.
				break; // No use in checking each signal if one does not match the issue pattern.
			}
		}

		if (patternMatches)
		{
			// Get the message of the issue the signals outlined.
			return issues[i].getMessage();
		}
	}
	return "Normal";
}
