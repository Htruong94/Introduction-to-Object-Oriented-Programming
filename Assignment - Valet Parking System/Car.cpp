/* Citation and Sources...
Final Project Milestone 6
Module: Cars
Filename: Cars.cpp
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
#include "Car.h"

using namespace sdds;

Car::Car() : Vehicle() {
	carwash = false;
}

Car::Car(const char* lp, const char* mamo, bool cw) : Vehicle(lp, mamo) {
	carwash = false;
	carwash = cw;
}

std::istream& Car::read(std::istream& istr) {
	char yesNo[16] = {'\0'};
	if (isCsv()) {
		Vehicle::read(istr);
		istr >> carwash;
	}
	else {
		std::cout << std::endl << "Car information entry" << std::endl;
		Vehicle::read(istr);
		std::cout << "Carwash while parked? (Y)es/(N)o: ";
		istr >> yesNo;
		istr.ignore(2000, '\n');
		istr.clear();
		while ((yesNo[0] != 'y' && yesNo[0] != 'Y' && yesNo[0] != 'n' && yesNo[0] != 'N') || yesNo[1] != '\0') {
			std::cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
			istr >> yesNo;
			istr.ignore(2000, '\n');
			istr.clear();
		}
		if (yesNo[0] == 'y' || yesNo[0] == 'Y') {
			carwash = true;
		}
	}
	return istr;
}

std::ostream& Car::write(std::ostream& ostr) const {
	if (isEmpty()) {
		ostr << "Invalid Car Object" << std::endl;
	}
	else {
		if (isCsv()) {
			ostr << "C,";
			Vehicle::write(ostr);
			ostr << carwash << std::endl;
		}
		else {
			ostr << "Vehicle type: Car" << std::endl;
			Vehicle::write(ostr);
			if (carwash) {
				ostr << "With Carwash" << std::endl;
			}
			else {
				ostr << "Without Carwash" << std::endl;
			}
		}
	}

	return ostr;
}
