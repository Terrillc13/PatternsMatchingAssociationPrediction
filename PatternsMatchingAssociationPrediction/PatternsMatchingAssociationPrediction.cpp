// PatternsMatchingAssociationPrediction.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string> 
#include "Signal.h"
using namespace std;

int main()
{
	cout << "Signal Creation" << endl;
	Signal signal1;
	Signal signal2;
	Signal signal3;
	Signal signal4;
	Signal signal5;
	signal1.setIsAbnormal(false);
	signal2.setIsAbnormal(false);
	signal3.setIsAbnormal(false);
	signal4.setIsAbnormal(false);
	signal5.setIsAbnormal(false);
	cout << signal1.getIsAbnormal() << endl;
	cout << signal2.getIsAbnormal() << endl;
	cout << signal3.getIsAbnormal() << endl;
	cout << signal4.getIsAbnormal() << endl;
	cout << signal5.getIsAbnormal() << endl;
	cout << "Signal 2 Modified" << endl;
	signal2.setIsAbnormal(true);
	cout << signal1.getIsAbnormal() << endl;
	cout << signal2.getIsAbnormal() << endl;
	cout << signal3.getIsAbnormal() << endl;
	cout << signal4.getIsAbnormal() << endl;
	cout << signal5.getIsAbnormal() << endl;

	system("PAUSE");
    return 0;
}

