/* Citation and Sources...
Final Project Milestone 6
Module: Motorcycle
Filename: Motorcycle.cpp
Version 1.1
Author Hung Truong - 147779193
Revision History
-----------------------------------------------------------
Date Reason
July 25, 2020 - Initial Release
July 27, 2020 - Fixed issues found in milestone 6 within write function
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
#include "Motorcycle.h"

using namespace sdds;

Motorcycle::Motorcycle() : Vehicle() {
	sidecar = false;
}

Motorcycle::Motorcycle(const char* lp, const char* mamo, bool sc) : Vehicle(lp, mamo) {
	sidecar = sc;
}

std::istream& Motorcycle::read(std::istream& istr) {
	char yesNo[16] = {'\0'};
	if (isCsv()) {
		Vehicle::read(istr);
		istr >> sidecar;
	}
	else {
		std::cout << std::endl << "Motorcycle information entry" << std::endl;
		Vehicle::read(istr);
		std::cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";
		istr >> yesNo;
		istr.ignore(2000, '\n');
		istr.clear();
		while ((yesNo[0] != 'y' && yesNo[0] != 'Y' && yesNo[0] != 'n' && yesNo[0] != 'N') || yesNo[1] != '\0') {
			yesNo[0] = '\0';
			std::cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
			istr >> yesNo;
			istr.ignore(2000, '\n');
			istr.clear();
		}
		if (yesNo[0] == 'y' || yesNo[0] == 'Y') {
			sidecar = true;
		}
	}
	return istr;
}

std::ostream& Motorcycle::write(std::ostream& ostr) const {
	if (isEmpty()) {
		ostr << "Invalid Motorcycle Object" << std::endl;
	}
	else {
		if (isCsv()) {
			ostr << "M,";
			Vehicle::write(ostr);
			ostr << sidecar << std::endl;
		}
		else {
			ostr << "Vehicle type: Motorcycle" << std::endl;
			Vehicle::write(ostr);
			if (sidecar) {
				ostr << "With Sidecar" << std::endl;
			}
		}
	}
	return ostr;
}
