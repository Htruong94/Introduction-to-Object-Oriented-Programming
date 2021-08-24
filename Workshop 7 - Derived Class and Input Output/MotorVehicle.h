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

#ifndef MOTORVEHICLE_H
#define MOTORVEHICLE_H
#include<iostream>

namespace sdds {
	class MotorVehicle {
		char m_LPnum[32]; //license plate number
		char m_vehAdd[64]; //address of the vehicle at a given moment
		int m_carYear; //Year when vehicle was made
	public:
		MotorVehicle(const char*, int, const char* = "Factory"); //custom constructor of MotorVehicle class
		void moveTo(const char* address); //changes the address of the vehicle if new address is not the same as the current address and prints change
		std::ostream& write(std::ostream& os) const; //query that inserts os to the content and displays a format message
		std::istream& read(std::istream& in); //reads the data in stream
	};
	std::ostream& operator<< (std::ostream& os, const MotorVehicle& src); //overload extraction operator to call write
	std::istream& operator>> (std::istream& in, MotorVehicle& src);//overload insertion operator to call read
}

#endif

