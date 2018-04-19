#pragma once
#include <string>
using namespace std;

class Issue
{
	/* The variables used in this class. */
	string message; // String value that displays the Issue.
	bool pattern[5]; // Boolean array that represents the Issue Pattern.
public:

	/* The function signatures for this class. */
	Issue();
	Issue(string message, bool pattern[]);
	~Issue();
	void setMessage(string message);
	void setPattern(bool pattern[]);
	bool* getPattern();
	string getMessage();
};

