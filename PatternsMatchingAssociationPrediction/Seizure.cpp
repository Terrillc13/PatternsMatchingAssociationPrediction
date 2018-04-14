/**
Seizure Class is used as a control class
that compares the Signal objects with the
Issue object patterns and determines if there
is a problem being outlined by the signals.
Created By: Clayton D. Terrill and Ian Barney
April 14th, 2018.
*/

#include "stdafx.h"
#include "Seizure.h"

/**
Function: Issue
Default Constructor of the Issue.
Only needed to access the class.
*/
Seizure::Seizure()
{
}

/**
Function: ~Seizure
Default Destructor that deletes the Seizure class. Prevents Memory Leak.
No memory allocated in this class, so no deallocation is needed.
*/
Seizure::~Seizure()
{
}

/**
Function: checkForSeizure
Compares the Signals in the Signal array with each Issue's pattern.
@param signalArray - Pointer to the signalArray which allows access.
@param issueArray - Pointer to the issueArray which allows access.
@return bool* - Pointer to the Boolean pattern array.
*/
string Seizure::checkForSeizure(Signal* signalArray, Issue* issueArray)
{
	bool* patternTemp; // The current issue pattern array being observed.
	bool patternMatches; // Flag for whether an issue pattern matches the signals or not.

	// Iterate through the issues and check their patterns.
	for (int i = 0; i < sizeof(issueArray) - 1; i++)
	{
		patternMatches = true; // Assume that the pattern matches.
		patternTemp = issueArray[i].getPattern(); // Set the current issue pattern array being observed.

		// Check each signal with the current issue pattern.
		for (int j = 0; j <= sizeof(patternTemp); j++)
		{
			if (patternTemp[j] != signalArray[j].getIsAbnormal())
			{
				// There was a discrepency between the issue pattern and a signal.
				patternMatches = false; // The pattern does not correspond with the signals.
				break; // No use in checking each signal if one does not match the issue pattern.
			}
		}

		if (patternMatches)
		{
			// Get the message of the issue the signals outlined.
			return issueArray[i].getMessage();
		}
	}
	return "Normal";
}