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
using namespace std;

/**
Function: printSignals
Print isAbnormal for each Signal object in the signalArray.
@param signalArray - Pointer to the signalArray which allows access.
*/
void printSignals(Signal* signalArray) {
	// Print out isAbnormal for every Signal in the array.
	for (int i = 0; i <= sizeof(signalArray); i++)
	{
		cout << signalArray[i].getIsAbnormal() << endl;
	}
}

/**
Function: printIssues
Prints entire pattern for each Issue object in the issueArray.
@param issueArray - Pointer to the issueArray which allows access.
*/
void printIssues(Issue* issueArray) {
	bool* patternTemp;
	// Print out isAbnormal for every Signal in the array.
	for (int i = 0; i < sizeof(issueArray)-1; i++)
	{
		cout << "Pattern " << i + 1 << endl;
		patternTemp = issueArray[i].getPattern();

		for (int j = 0; j <= sizeof(patternTemp); j++)
		{
			cout << patternTemp[j] << endl;
		}
		cout << "Issue: " << issueArray[i].getMessage() << endl << endl;
	}
}


/**
Function: printSignals
Print isAbnormal for each Signal object in the signalArray.
@param signalArray - Pointer to the signalArray which allows access.
*/
bool testSignals(Signal* signalArray) {
	try {
		cout << "********** DEFAULT SIGNALS **********" << endl << endl;
		signalArray[0].setIsAbnormal(false);
		signalArray[1].setIsAbnormal(false);
		signalArray[2].setIsAbnormal(false);
		signalArray[3].setIsAbnormal(false);
		signalArray[4].setIsAbnormal(false);
		printSignals(signalArray);
		cout << endl;

		cout << "********** MODIFIED SIGNALS **********" << endl << endl;
		cout << "Signal 1 Modified" << endl;
		signalArray[0].setIsAbnormal(true);
		printSignals(signalArray);
		cout << endl;

		cout << "Signal 2 Modified" << endl;
		signalArray[1].setIsAbnormal(true);
		printSignals(signalArray);
		cout << endl;

		cout << "Signal 3 Modified" << endl;
		signalArray[2].setIsAbnormal(true);
		printSignals(signalArray);
		cout << endl;

		cout << "Signal 4 Modified" << endl;
		signalArray[3].setIsAbnormal(true);
		printSignals(signalArray);
		cout << endl;

		cout << "Signal 5 Modified" << endl;
		signalArray[4].setIsAbnormal(true);
		printSignals(signalArray);
		cout << endl;

		cout << "Reset Signals to False" << endl;
		signalArray[0].setIsAbnormal(false);
		signalArray[1].setIsAbnormal(false);
		signalArray[2].setIsAbnormal(false);
		signalArray[3].setIsAbnormal(false);
		signalArray[4].setIsAbnormal(false);
		printSignals(signalArray);
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
@param signalArray - Pointer to the signalArray which allows access.
*/
bool testIssues(Issue* issueArray) {
	try {

		cout << "********** DEFAULT ISSUES **********" << endl << endl;
		printIssues(issueArray);

		bool issuePattern_1[5] = { true, true, true, true, true };
		string issueMessage_1 = "Seizure Detected: EMERGENCY (Complete bodily shutdown)";

		bool issuePattern_2[5] = { true, false, false, false, true };
		string issueMessage_2 = "Seizure Detected: Minor (Sudden, repeated fear or anger)";

		bool issuePattern_3[5] = { true, false, true, false, true };
		string issueMessage_3 = "Seizure Detected: Minor (Repeated, unusual movements such as head nodding or rapid blinking";

		issueArray[0].setPattern(issuePattern_1);
		issueArray[0].setMessage(issueMessage_1);
		issueArray[1].setPattern(issuePattern_2);
		issueArray[1].setMessage(issueMessage_2);
		issueArray[2].setPattern(issuePattern_3);
		issueArray[2].setMessage(issueMessage_3);

		cout << "********** MODIFIED ISSUES **********" << endl << endl;
		printIssues(issueArray);
		
		cout << endl;

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
	/* Create the Signal array */
	cout << "Signal Creation" << endl;
	Signal signalArray[5];
	signalArray[0] = Signal();
	signalArray[1] = Signal();
	signalArray[2] = Signal();
	signalArray[3] = Signal();
	signalArray[4] = Signal();

	bool testSignalsSuccess = testSignals(signalArray);
	cout << endl;
	cout << "Test Signals Success: " << testSignalsSuccess << endl;
	cout << endl;
	cout << "Press any key to continue to the Issues Test" << endl;
	cin.ignore(); // Wait for any key

	/* Create the Issue array */
	cout << "Issue Creation" << endl;
	Issue issueArray[3];
	issueArray[0] = Issue();
	issueArray[1] = Issue();
	issueArray[2] = Issue();

	bool testIssuesSuccess = testIssues(issueArray);
	cout << endl;
	cout << "Test Issues Success: " << testIssuesSuccess << endl;
	cout << endl;
	cout << "Press any key to continue to the set Seizure Detection Test" << endl;
	cin.ignore(); // Wait for any key

	return 0;
}

