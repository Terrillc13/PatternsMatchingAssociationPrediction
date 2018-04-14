/**
Acts as the test driver for the program.
Created By: Clayton D. Terrill and Ian Barney
April 14th, 2018.
*/

#include "stdafx.h"
#include <iostream>
#include <string> 
#include "Signal.h"
#include "Issue.h"
#include "Seizure.h"
using namespace std;

/* Global Class Variables */
Seizure seizure; // Allows access to the seizure control class.
Signal* signalArray; // Pointer to the signalArray.
Issue* issueArray; // Pointer to the issueArray.

/* Test Issue Patterns to compare with the Signals*/
bool issuePattern_1[5] = { true, true, true, true, true };
string issueMessage_1 = "Seizure Detected: EMERGENCY (Complete bodily shutdown)";

bool issuePattern_2[5] = { true, false, false, false, true };
string issueMessage_2 = "Seizure Detected: Minor (Sudden, repeated fear or anger)";

bool issuePattern_3[5] = { true, false, true, false, true };
string issueMessage_3 = "Seizure Detected: Minor (Repeated, unusual movements such as head nodding or rapid blinking)";

/**
Function: printTestValues
Print the test values out.
@param issuePattern - Pointer to the test issuePattern which allows access.
@param issueMessage - Message for the test issue.
*/
void printTestValues(bool* issuePattern, string issueMessage) {
	cout << "	Pattern: ";
	// Print out every boolean value in the array.
	for (int i = 0; i <= sizeof(issuePattern); i++)
	{
		cout << issuePattern[i] << " ";
	}
	cout << endl << "	Message: " << issueMessage << endl;
}

/**
Function: printSignals
Print isAbnormal for each Signal object in the signalArray.
*/
void printSignals() {
	cout << "	Signals: ";
	// Print out isAbnormal for every Signal in the array.
	for (int i = 0; i <= sizeof(signalArray); i++)
	{
		cout << signalArray[i].getIsAbnormal() << " ";
	}
	cout << endl;
}

/**
Function: printIssues
Prints entire pattern for each Issue object in the issueArray.
@param issueArray - Pointer to the issueArray which allows access.
*/
void printIssues() {
	bool* patternTemp;
	// Print out isAbnormal for every Signal in the array.
	for (int i = 0; i < sizeof(issueArray)-1; i++)
	{
		cout << "	Issue " << i + 1 << endl;
		patternTemp = issueArray[i].getPattern();

		cout << "		Pattern: ";
		for (int j = 0; j <= sizeof(patternTemp); j++)
		{
			cout << patternTemp[j] << " ";
		}
		cout << endl << "		Issue: " << issueArray[i].getMessage() << endl << endl;
	}
}


/**
Function: printSignals
Print isAbnormal for each Signal object in the signalArray.
@param signalArray - Pointer to the signalArray which allows access.
*/
bool testSignals() {
	try {
		cout << "-DEFAULT SIGNALS:" << endl << endl;
		signalArray[0].setIsAbnormal(false);
		signalArray[1].setIsAbnormal(false);
		signalArray[2].setIsAbnormal(false);
		signalArray[3].setIsAbnormal(false);
		signalArray[4].setIsAbnormal(false);
		printSignals();
		cout << endl;

		cout << "-MODIFIED SIGNALS:" << endl << endl;
		cout << "	Signal 1 Modified" << endl;
		signalArray[0].setIsAbnormal(true);
		printSignals();
		cout << endl;

		cout << "	Signal 2 Modified" << endl;
		signalArray[1].setIsAbnormal(true);
		printSignals();
		cout << endl;

		cout << "	Signal 3 Modified" << endl;
		signalArray[2].setIsAbnormal(true);
		printSignals();
		cout << endl;

		cout << "	Signal 4 Modified" << endl;
		signalArray[3].setIsAbnormal(true);
		printSignals();
		cout << endl;

		cout << "	Signal 5 Modified" << endl;
		signalArray[4].setIsAbnormal(true);
		printSignals();
		cout << endl;

		cout << "-RESET SIGNALS" << endl;
		signalArray[0].setIsAbnormal(false);
		signalArray[1].setIsAbnormal(false);
		signalArray[2].setIsAbnormal(false);
		signalArray[3].setIsAbnormal(false);
		signalArray[4].setIsAbnormal(false);
		printSignals();
		cout << endl;

		return true;
	}
	catch (exception e) {
		return false;
	}
}

/**
Function: printSignals
Print isAbnormal for each Signal object in the signalArray.
@param issueArray - Pointer to the issueArray which allows access.
*/
bool testIssues() {
	try {

		cout << "-DEFAULT ISSUES:" << endl << endl;
		printIssues();


		cout << "-MODIFIED ISSUES:" << endl << endl;

		issueArray[0].setPattern(issuePattern_1);
		issueArray[0].setMessage(issueMessage_1);
		issueArray[1].setPattern(issuePattern_2);
		issueArray[1].setMessage(issueMessage_2);
		issueArray[2].setPattern(issuePattern_3);
		issueArray[2].setMessage(issueMessage_3);
		printIssues();
		
		return true;
	}
	catch (exception e) {
		return false;
	}
}

/**
Function: testSetSeizure
Print isAbnormal for each Signal object in the signalArray.
@param issueArray - Pointer to the issueArray which allows access.
*/
bool testSetSeizure(bool* issuePattern, string issueMessage) {
	try {
		cout << "	Signals:	";
		// Set the signals to match the test issuePattern.
		for (int i = 0; i <= sizeof(signalArray); i++)
		{
			signalArray[i].setIsAbnormal(issuePattern[i]);
			cout << issuePattern[i] << " ";

		}
		cout << endl;

		string seizureMessage = seizure.checkForSeizure(signalArray, issueArray);
		cout << "	Test For:	" << issueMessage << endl;
		cout << "	Result:		" << seizureMessage << endl;
		return true;
	}
	catch (exception e) {
		return false;
	}
}

/**
Function: main
Initializes the objects and executes the test methods.
@return int - The exit status of the program.
*/
int main()
{
	/* Display the test values */
	cout << "******************** TEST VALUES ********************" << endl;
	cout << "Issue 1: " << endl;
	printTestValues(issuePattern_1, issueMessage_1);
	cout << "Issue 2: " << endl;
	printTestValues(issuePattern_2, issueMessage_2);
	cout << "Issue 3: " << endl;
	printTestValues(issuePattern_3, issueMessage_3);
	cout << endl;
	cout << "Press any key to continue to the Signals Test" << endl;
	cin.ignore(); // Wait for any key.
	cout << endl << endl << endl;

	/* Create the Signal array and test it */
	cout << "******************** SIGNAL CREATION AND TEST ********************" << endl;
	signalArray = new Signal[5];
	signalArray[0] = Signal();
	signalArray[1] = Signal();
	signalArray[2] = Signal();
	signalArray[3] = Signal();
	signalArray[4] = Signal();
	bool testSignalsSuccess = testSignals();
	cout << endl;
	cout << "Test Signals Success: " << testSignalsSuccess << endl;
	cout << endl;
	cout << "Press any key to continue to the Issues Test" << endl;
	cin.ignore(); // Wait for any key.
	cout << endl << endl << endl;

	/* Create the Issue array and test it */
	cout << "******************** ISSUE CREATION AND TEST ********************" << endl;
	issueArray = new Issue[3];
	issueArray[0] = Issue();
	issueArray[1] = Issue();
	issueArray[2] = Issue();
	bool testIssuesSuccess = testIssues();
	cout << endl;
	cout << "Test Issues Success: " << testIssuesSuccess << endl;
	cout << endl;
	cout << "Press any key to continue to the set Seizure Detection Test" << endl;
	cin.ignore(); // Wait for any key.
	cout << endl << endl << endl;

	/* Create the Seizure control and test it */
	cout << "******************** SEIZURE CONTROL CREATION AND SET TEST ********************" << endl;
	cout << endl << "Issue 1: " << endl;
	testSetSeizure(issuePattern_1, issueMessage_1); 
	cout << endl << "Issue 2: " << endl;
	testSetSeizure(issuePattern_2, issueMessage_2);
	cout << endl << "Issue 3: " << endl;
	testSetSeizure(issuePattern_3, issueMessage_3);
	cout << endl;
	cout << "Press any key to continue to the random Seizure Detection Test" << endl;
	cin.ignore(); // Wait for any key.
	cout << endl << endl << endl;

	return 0;
}

