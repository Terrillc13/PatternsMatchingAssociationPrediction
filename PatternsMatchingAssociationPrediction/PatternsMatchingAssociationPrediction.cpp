// PatternsMatchingAssociationPrediction.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string> 
#include "Signal.h"
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
Function: printSignals
Print isAbnormal for each Signal object in the signalArray.
@param signalArray - Pointer to the signalArray which allows access.
*/
void testSignals(Signal* signalArray) {
	signalArray[0].setIsAbnormal(false);
	signalArray[1].setIsAbnormal(false);
	signalArray[2].setIsAbnormal(false);
	signalArray[3].setIsAbnormal(false);
	signalArray[4].setIsAbnormal(false);
	printSignals(signalArray);
	cout << endl;

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
}

int main()
{
	cout << "Signal Creation" << endl;
	Signal signalArray[5];
	signalArray[0] = new Signal();
	signalArray[1] = new Signal();
	signalArray[2] = new Signal();
	signalArray[3] = new Signal();
	signalArray[4] = new Signal();

	testSignals(signalArray);

	system("PAUSE");
	return 0;
}

