/* Citation and Sources...
Final Project Milestone 6
Module: Cars
Filename: Cars.h
Version 1.0
Author Hung Truong - 147779193
Revision History
-----------------------------------------------------------
Date Reason
July 25, 2020 - Initial Release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/
#ifndef CAR_H
#define CAR_H


#include "Vehicle.h"

namespace sdds {
	class Car : public Vehicle {
		bool carwash; //variable telling if car is having a carwash or not
	public:
		//Public Constructor Implementation:
		Car(); //no-argument constructor setting car to safe invalid state
		Car(const char* lp, const char* mamo, bool cw = false); //constructor with parameters "license plate number" and "make and model", set to empty state if invalid parameters or parameters are pointed to null
		Car(const Car&) = delete; //copy function prohibited
		Car& operator = (const Car&) = delete; //copy assign function prohibited
		
		//Public Operator Overload Implementations:
		std::istream& read(std::istream& istr = std::cin); //Read override function from ReadWritable class
		std::ostream& write(std::ostream& ostr = std::cout) const; //Write override function from RewadWritable class
	};
}

#endif