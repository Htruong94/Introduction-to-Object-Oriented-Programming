/* Citation and Sources...
Final Project Milestone 6
Module: Utils
Filename: Utils.h
Version 1.0
Author Hung Truong
Revision History
-----------------------------------------------------------
Date Reason
July 23, 2020 - Initial Release
July 26, 2020 - Added new functions
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/

#ifndef UTILS_H
#define UTILS_H

namespace sdds {
	int wordLength(const char*); //obtains the length of the string
	int strCmp(const char*, const char*); //compares two strings and return a value, 0 == match, adapted from workshop 1
	int getInt(int, int); //obtains a min and max value when called and takes input of user until a valid input is obtained
	char yesNo(); //obtains a yes or no response from user
}

#endif
