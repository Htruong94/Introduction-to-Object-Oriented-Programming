/* Citation and Sources...
Final Project Milestone 6
Module: Utils
Filename: Utils.cpp
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
#include <iostream>
#include "Utils.h"

using namespace sdds;

int sdds::wordLength(const char* desc) {//alternatively use strlen, using loop to find string length
	int count = 0;

	for (count = 0; desc[count] != '\0'; count++){}

	return count;
}

int sdds::strCmp(const char* str1, const char* str2) {
	int i;
	for (i = 0; str1[i] && str2[i] && str1[i] == str2[i]; i++);
	return str1[i] - str2[i];
}

int sdds::getInt(int min, int max) {
	int igr = 0;
	char bfr;

	bool integer = false;
	while (!integer) {
		if (std::cin >> igr) { //if integer is input first
			if (std::cin.get(bfr)) { //obtains buffer input
				std::cin.putback(bfr); //place bfr back into buffer 
				if (bfr == '\n') {  //if the input after the integer is enter
					if (igr < min || igr > max) {
						std::cout << "Invalid selection, try again: ";
					}
					else {
						integer = true;
					}
				}
				else { //if the input after the integer is not enter
					std::cout << "Invalid trailing characters, try again: ";
				}
			}
			std::cin.clear(); //clears buffers
		}
		else { //if integer is not obtained from input
			std::cout << "Invalid Integer, try again: ";
			std::cin.clear();
		}
		std::cin.ignore(100, '\n'); //ignore and discard 100 chacters before the \n
	}

	return igr;
}

char sdds::yesNo() {
	char choice[16] = { '\0' }; //takes up to 16 characters, initialize choice
	std::cin >> choice;
	std::cin.clear(); //clears buffer
	std::cin.ignore(1000, '\n');
	//Repeats until a valid option is inputted
	while ((choice[0] != 'Y' && choice[0] != 'N' && choice[0] != 'y' && choice[0] != 'n') || choice[1] != '\0') {
		choice[0] = { '\0' }; //reset choice back to default
		std::cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
		std::cin >> choice;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
	}

	return choice[0];
}