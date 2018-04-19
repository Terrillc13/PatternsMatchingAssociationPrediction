/**
Acts as the test driver for the program.
Created By: Clayton D. Terrill
April 10th, 2018.
*/
#include "stdafx.h"
#include <iostream>
#include <string> 
#include <ctime>
#include <cstdlib>
#include "Signal.h"
#include "Issue.h"
#include "Patient.h"
using namespace std;

/* Global Class Variables */
Signal* signalArray; // Pointer to the signalArray.
Issue* issueArray; // Pointer to the issueArray.
Patient patient; // Allows access to the patient class.

				 /* Test Issue Patterns to compare with the Signals*/
bool issuePattern_1[5] = { true, true, true, true, true };
string issueMessage_1 = "Seizure Detected: EMERGENCY (Complete bodily shutdown)";

bool issuePattern_2[5] = { true, false, false, false, true };
string issueMessage_2 = "Seizure Detected: Minor (Sudden, repeated fear or anger)";

bool issuePattern_3[5] = { true, false, true, false, true };
string issueMessage_3 = "Seizure Detected: Minor (Repeated, unusual movements such as head nodding or rapid blinking)";

/* Test Patient Stats to compare with the Signals*/
int patientStats[2][5] = { { 100, 50, 80, 20, 130 },{ 130, 100, 150, 40, 180 } };

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
Function: printStats
Print stats of a given array.
@param stats - Integer Array to be printed out.
*/
void printStats(int stats[2][5]) {
	// Print out every boolean value in the array.
	for (int i = 0; i < 5; i++)
	{
		cout << "	Range  " << i + 1 << ": " << stats[0][i] << " to " << stats[1][i] << endl;
	}
}

/**
Function: printStats
Print stats of the Patient object.
*/
void printPatientStats() {
	cout << "Patient Stat Ranges: " << endl;
	// Print out every boolean value in the array.
	for (int i = 0; i < 5; i++)
	{
		cout << "	Signal " << i + 1 << ": " << patient.getStats(0, i) << " to " << patient.getStats(1, i) << endl;
	}
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
		cout << signalArray[i].getFrequency() << " ";
	}
	cout << endl;
}

/**
Function: printIssues
Prints entire pattern for each Issue object in the issueArray.
*/
void printIssues() {
	bool* patternTemp;
	// Print out isAbnormal for every Signal in the array.
	for (int i = 0; i < sizeof(issueArray) - 1; i++)
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
Function: testSignals
Test to make sure Siganl attributes are modified correctly.
*/
bool testSignals() {
	try {
		cout << "-DEFAULT SIGNALS:" << endl << endl;
		signalArray[0].setFrequency(0);
		signalArray[1].setFrequency(0);
		signalArray[2].setFrequency(0);
		signalArray[3].setFrequency(0);
		signalArray[4].setFrequency(0);
		printSignals();
		cout << endl;

		cout << "-MODIFIED SIGNALS:" << endl << endl;
		cout << "	Signal 1 Modified" << endl;
		signalArray[0].setFrequency(11);
		printSignals();
		cout << endl;

		cout << "	Signal 2 Modified" << endl;
		signalArray[1].setFrequency(22);
		printSignals();
		cout << endl;

		cout << "	Signal 3 Modified" << endl;
		signalArray[2].setFrequency(33);
		printSignals();
		cout << endl;

		cout << "	Signal 4 Modified" << endl;
		signalArray[3].setFrequency(44);
		printSignals();
		cout << endl;

		cout << "	Signal 5 Modified" << endl;
		signalArray[4].setFrequency(55);
		printSignals();
		cout << endl;

		cout << "-RESET SIGNALS" << endl;
		signalArray[0].setFrequency(0);
		signalArray[1].setFrequency(0);
		signalArray[2].setFrequency(0);
		signalArray[3].setFrequency(0);
		signalArray[4].setFrequency(0);
		printSignals();
		cout << endl;

		return true;
	}
	catch (exception e) {
		return false;
	}
}

/**
Function: testIssues
Test to make sure Issue attributes are modified correctly.
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
Function: testIssues
Test to make sure Patient attributes are modified correctly.
*/
bool testPatient() {
	try {

		cout << "-DEFAULT PATIENT STATISTICS:" << endl << endl;
		printPatientStats();

		cout << endl << "-MODIFIED PATIENT STATISTICS:" << endl;

		cout << endl << "Test Valid Range: " << endl;
		int testStats1[2][5] = { { 1, 2, 3, 4, 5 },{ 11, 12, 13, 14, 15 } };
		printStats(testStats1);
		patient.setStats(testStats1);
		printPatientStats();


		cout << endl << "Test Invalid Range at Signal 3: " << endl;
		int testStats2[2][5] = { { 101, 102, 103, 104, 105 },{ 102, 103, 2, 105, 106 } };
		printStats(testStats2);
		patient.setStats(testStats2);
		printPatientStats();

		cout << endl << "-RESET PATIENT STATS" << endl;
		int testStats3[2][5] = { { 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0 } };
		printStats(testStats3);
		patient.setStats(testStats3);
		printPatientStats();

		return true;
	}
	catch (exception e) {
		return false;
	}
}

/**
Function: testSetSeizure
Test to make sure classes behave properly together using test cases.
@param testSignal - Array of signals to test.
@param issueMessage - Issue message to expect.
*/
bool testSetSeizure(int testSignal[5], string issueMessage) {
	try {
		cout << "	Signals:	";
		// Set the signals to match the test signal pattern.
		for (int i = 0; i <= sizeof(signalArray); i++)
		{
			signalArray[i].setFrequency(testSignal[i]);
			cout << testSignal[i] << " ";

		}
		cout << endl;

		// Detect abnormal signals relative to stats.
		patient.checkRanges(signalArray);
		// Match abnormal signal patterns with issue patterns.
		string seizureMessage = patient.matchPattern(issueArray);
		cout << "	Test For:	" << issueMessage << endl;
		cout << "	Result:		" << seizureMessage << endl;
		return true;
	}
	catch (exception e) {
		return false;
	}
}

/**
Function: testRandomSeizure
Test to make sure classes behave properly together using randomly generated signals.
*/
bool testRandomSeizure() {
	try {
		srand(time(0));
		int r;
		cout << "	Signals:	";
		// Set the signals to match the test issuePattern.
		for (int i = 0; i <= sizeof(signalArray); i++)
		{
			// Generate random number between 0 and 200.
			r = (rand() % 200) + 0;
			signalArray[i].setFrequency(r);
			cout << r << " ";
		}
		cout << endl;

		// Detect abnormal signals relative to stats.
		patient.checkRanges(signalArray);
		// Match abnormal signal patterns with issue patterns.
		string seizureMessage = patient.matchPattern(issueArray);
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
	cout << "Test Stat Ranges: " << endl;
	printStats(patientStats);
	cout << endl;
	cout << "Press enter to continue to the Signals Test" << endl;
	cin.ignore(); // Wait for enter.
	cout << endl << endl << endl;

	/* Create the Signal array and test it */
	cout << "******************** SIGNALS TEST ********************" << endl;
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
	cout << "Press enter to continue to the Issues Test" << endl;
	cin.ignore(); // Wait for enter.
	cout << endl << endl << endl;

	/* Create the Issue array and test it */
	cout << "******************** ISSUES TEST ********************" << endl;
	issueArray = new Issue[3];
	issueArray[0] = Issue();
	issueArray[1] = Issue();
	issueArray[2] = Issue();
	bool testIssuesSuccess = testIssues();
	cout << endl;
	cout << "Test Issues Success: " << testIssuesSuccess << endl;
	cout << endl;
	cout << "Press enter to continue to the patients test..." << endl;
	cin.ignore(); // Wait for enter.
	cout << endl << endl << endl;

	/* Create the patient and test it */
	cout << "******************** PATIENTS TEST ********************" << endl;
	bool testPatientsSuccess = testPatient();
	cout << endl;
	cout << "Test Issues Success: " << testPatientsSuccess << endl;
	cout << endl;
	cout << "Press enter to continue to the program default test..." << endl;
	cin.ignore(); // Wait for enter.
	cout << endl << endl << endl;

	/* Test the overall functionality of the program using test cases */
	cout << "******************** PROGRAM DEFAULT TEST ********************" << endl;
	//{ { 100, 50, 80, 20, 130 },{ 130, 100, 150, 40, 180 } };
	/*
	bool issuePattern_1[5] = { true, true, true, true, true };
	string issueMessage_1 = "Seizure Detected: EMERGENCY (Complete bodily shutdown)";

	bool issuePattern_2[5] = { true, false, false, false, true };
	string issueMessage_2 = "Seizure Detected: Minor (Sudden, repeated fear or anger)";

	bool issuePattern_3[5] = { true, false, true, false, true };
	string issueMessage_3 = "Seizure Detected: Minor (Repeated, unusual movements such as head nodding or rapid blinking)";

	int patientStats[2][5] = { { 100, 50, 80, 20, 130 },{ 130, 100, 150, 40, 180 } };
	*/
	cout << endl << "-USE TEST PATIENT STATS" << endl;
	patient.setStats(patientStats);
	printPatientStats();
	cout << endl << "Test for Issue 1: " << endl;
	int test1[5] = { 90, 110, 40, 80, 10 }; // True, True, True, True, True
	testSetSeizure(test1, issueMessage_1);
	cout << endl << "Test for Issue 2: " << endl;
	int test2[5] = { 90, 75, 110, 30, 10 }; // True, False, False, False, True
	testSetSeizure(test2, issueMessage_2);
	cout << endl << "Test for Issue 3: " << endl;
	int test3[5] = { 90, 75, 500, 30, 10 }; // True, False, True, False, True
	testSetSeizure(test3, issueMessage_3);
	cout << endl << "Test All Signals for Lower Boundary: " << endl;
	int test4[5] = { 100, 50, 80, 20, 130 }; // True, False, True, False, True
	testSetSeizure(test4, "Normal");
	cout << endl << "Test All Signals for One Below Lower Boundary: " << endl;
	int test5[5] = { 99, 49, 79, 19, 129 }; // True, False, True, False, True
	testSetSeizure(test5, issueMessage_1);
	cout << endl << "Test All Signals for Upper Boundary: " << endl;
	int test6[5] = { 130, 100, 150, 40, 180 }; // True, False, True, False, True
	testSetSeizure(test6, "Normal");
	cout << endl << "Test All Signals for One Above Upper Boundary: " << endl;
	int test7[5] = { 131, 101, 151, 41, 181 }; // True, False, True, False, True
	testSetSeizure(test7, issueMessage_1);
	cout << endl;
	cout << "Press enter to continue to the program random signals test..." << endl;
	cin.ignore(); // Wait for enter.
	cout << endl << endl << endl;

	/* Test the overall functionality of the program using random signals */
	cout << "******************** PROGRAM RANDOM SIGNALS TEST ********************" << endl;
	cout << endl << "-USE TEST PATIENT STATS" << endl;
	printPatientStats();
	int k = 0;
	string line;
	bool loop = true;
	for (;;)
	{

		cout << endl << "Test " << ++k << ": " << endl;
		testRandomSeizure();
		cout << endl;
		cout << "Press enter to execute another random test. Enter 'q' to exit..." << endl;
		getline(cin, line);
		if (line == "q") break;
	}

	return 0;
}

