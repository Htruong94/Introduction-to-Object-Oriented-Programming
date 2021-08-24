/* Citation and Sources...
Final Project Milestone 6
Module: Vehicle
Filename: Vehicle.h
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

#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include "ReadWritable.h"

namespace sdds {
	const int MAX_LP_NUM_LEN = 8;

	class Vehicle: public ReadWritable {
		char m_license[MAX_LP_NUM_LEN+1]; //License plate number of 1-8 characters
		char* m_makemodel; //make and model value, cannot be null/empty
		int m_parkspotnum; //spot number of where vehicle is parked, 0 represents not-parked
	public:
		//Public Constructor Implementation:
		Vehicle(); //default constructor of Vehicle class that sets vehicle to empty state
		Vehicle(const char* license, const char* makemodel, int parkspotnum = 0); //custom constructor of vehicle class given license plate and make model. Park Spot can be taken but default to 0 
		Vehicle(const Vehicle&) = delete; //Copy constructor prohibited
		Vehicle& operator = (const Vehicle&) = delete; //Copy assignment prohibited
		~Vehicle(); //Destructor of Vehicle class

		//Member Function and Operator overload implementation:
		int getParkingSpot() const; //returns the value of the parking spot number of vehicle
		void setParkingSpot(int parkspot); //resets value of parking spot number to new value, vehicle empty state if value is invalid
		bool operator==(const char* license) const; //compares vehicles license plate number with given license number and return true if the same, false if not
		bool operator==(const Vehicle&) const; //compares both vehicles license plate number and return true if they match, else false
		std::istream& read(std::istream& istr = std::cin); //Read override function from ReadWritable class
		std::ostream& write(std::ostream& ostr = std::cout) const; //Write override function from RewadWritable class
		void strCpy(char*, const char*); //string copy from one string to another, adapted from workshop 1
	protected:
		void setEmpty(); //sets vehicle to invalid empty state
		bool isEmpty() const; //returns true if vehicle is in invalid empty state, false if not
		const char* getLicensePlate(); // read only address of license plate of vehicle
		const char* getMakeModel(); // ready only address of make and model of vehicle
		void setMakeModel(const char* makemodel); // resets make and model and set to new value, empty state if new value is null/empty
	};
}

#endif