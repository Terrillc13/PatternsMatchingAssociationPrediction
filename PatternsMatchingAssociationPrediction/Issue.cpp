/**
Issue Class is used to create an Issue object
that represents an Issue Pattern. The Issue Pattern
will be compared with to see if that specific Issue
is occurring.
Created By: Clayton D. Terrill and Ian Barney
April 14th, 2018.
*/
#include "stdafx.h"
#include "Issue.h"
using namespace std;

/**
Function: Issue
Default Constructor of the Issue.
Initialize the size of the boolean array to 5.
Initializes the pattern to be all true.
Initializes the message as 'Detected an Issue'.
*/
Issue::Issue()
{
	// Use 5 as the default size of the pattern array.
	pattern = new bool[5];

	// Initialize the pattern to  be all true.
	for (int i = 0; i <= sizeof(pattern); i++)
	{
		this->pattern[i] = true;
	}
	this->message = "Detected an Issue";
}

/**
Function: Issue
Constructor for when a boolean array and message has been 
designated during the Issue object creation.
Sets the pattern array.
Sets the message.
@param patternTemp - The array to set the pattern array with.
@param messageTemp - String value that contains the Issue.
*/
Issue::Issue(bool* patternTemp, string messageTemp)
{
	// Set the size of the pattern array to the size of the array being passed in.
	pattern = new bool[sizeof(patternTemp)];

	// Initialize the pattern to  be all true.
	for (int i = 0; i <= sizeof(patternTemp); i++)
	{
		this->pattern[i] = true;
	}
	this->message = messageTemp;
}

/**
Function: ~Issue
Default Destructor that deletes the Issue. Prevents Memory Leak.
*/
Issue::~Issue()
{
	//delete[] pattern;
}

/**
Function: setPattern
Sets the pattern array.
@param patternTemp - The array to set the pattern array with.
*/
void Issue::setPattern(bool* patternTemp)
{
	// Set the size of the pattern array to the size of the array being passed in.
	pattern = new bool[sizeof(patternTemp)];

	// Initialize the pattern to  be all true.
	for (int i = 0; i <= sizeof(patternTemp); i++)
	{
		this->pattern[i] = patternTemp[i];
	}
}

/**
Function: setMessage
Sets the message variable with a String value.
@param messageTemp - String value that contains the Issue.
*/
void Issue::setMessage(string messageTemp)
{
	this->message = messageTemp;
}


/**
Function: getPattern
Returns Issue Pattern.
@return bool* - Pointer to the Boolean pattern array.
*/
bool* Issue::getPattern()
{
	return this->pattern;
}

/**
Function: getMessage
Returns the Issue message.
@return string - String containing the Issue message.
*/
string Issue::getMessage()
{
	return this->message;
}