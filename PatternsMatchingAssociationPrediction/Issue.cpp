/**
Issue Class is used to create an Issue object
that represents an Issue Pattern. The Issue Pattern
will be compared with to see if that specific Issue
is occurring.
Created By: Clayton D. Terrill and Ian Barney
April 10th, 2018.
*/

#include "stdafx.h"
#include "Issue.h"
#include <iostream>
using namespace std;

/**
Function: Issue
Default Constructor of the Issue.
Initializes the pattern to be all true.
Initializes the message as 'Detected an Issue'.
*/
Issue::Issue()
{
	// Initialize the pattern to  be all true.
	for (int i = 0; i < 5; i++) {
		this->pattern[i] = true;
	}
	this->message = "Detected an Issue";
}

Issue::Issue(string message, bool pattern[])
{
	// Calling set functions allow for only one method to need modified.
	this->setMessage(message);
	this->setPattern(pattern);
}

/**
Function: ~Issue
Default Destructor that deletes the Issue. Prevents Memory Leak.
*/
Issue::~Issue()
{
}

/**
Function: setMessage
Sets the message variable with a String value.
@param message - String value that contains the Issue.
*/
void Issue::setMessage(string message)
{
	this->message = message;
}

/**
Function: setPattern
Sets the pattern array.
@param pattern - The array to set the pattern array with.
*/
void Issue::setPattern(bool pattern[])
{
	for (int i = 0; i < 5; i++) {
		this->pattern[i] = pattern[i];
	}
}

/**
Function: getPattern
Returns Issue Pattern.
@return bool* - Pointer to the Boolean pattern array.
*/
bool* Issue::getPattern()
{
	return pattern;
}

/**
Function: getMessage
Returns the Issue message.
@return string - String containing the Issue message.
*/
string Issue::getMessage() {
	return this->message;
}
