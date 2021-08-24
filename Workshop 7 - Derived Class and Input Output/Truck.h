//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

//==============================================
// Name:           Hung Truong
// Student Number: 147779193
// Email:          htruong19@myseneca.ca
// Section:        NAA
// Date:           July 14, 2020
//==============================================
// Workshop:       7
//==============================================

#ifndef TRUCK_H
#define TRUCK_H
#include <iostream>
#include "MotorVehicle.h"

namespace sdds {
	class Truck: public MotorVehicle {
		double m_capacity; //maximum weight of the cargo the truck can carry
		double m_cargoLoad; //weight of the load, cannot exceed capacity
	public:
		Truck(const char*, int, double, const char*, double = 0); //custom constructor of truck class
		bool addCargo(double cargo); //adds cargo value to cargoload, if exceeds capacity, set value to capacity, if value is capacity, return 0
		bool unloadCargo(); //if there is a cargo, set cargoload to 0 and return true, false if there is no cargo to unload
		std::ostream& write(std::ostream& os) const; //displays information of the truck on screen
		std::istream& read(std::istream& in); //takes input from user and store into the variables
	};
	std::ostream& operator<<(std::ostream& os, const Truck& src); //extraction operator to extract class from stream
	std::istream& operator>>(std::istream& in, Truck& src); //insertion operator to insert class into stream

}

#endif

