#pragma once
#include <string> // Needed in header for the String variable.
using namespace std; // Needed in header for the String variable.

/**
Issue Class is used to create an Issue object
that represents an Issue Pattern. The Issue Pattern
will be compared with to see if that specific Issue
is occurring.
Created By: Clayton D. Terrill and Ian Barney
April 14th, 2018.
*/
class Issue
{
public:
	/* The variables used in this class. */
	string message; // String value that displays the Issue.
	bool* pattern; // Boolean array that represents the Issue Pattern.

	/* The function signatures for this class. */
	Issue();
	Issue(bool*, string);
	~Issue();
	void setPattern(bool*);
	void setMessage(string);
	bool* getPattern();
	string getMessage();
};

