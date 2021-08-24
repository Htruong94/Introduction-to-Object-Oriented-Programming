/* Citation and Sources...
Final Project Milestone 6
Module: Parking
Filename: Parking.h
Version 1.1
Author Hung Truong - 147779193
Revision History
-----------------------------------------------------------
Date Reason
2020/7/16 Prelimary Release
2020/7/26 Added new functions
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/
#ifndef PARKING_H
#define PARKING_H

#include "Menu.h"
#include "Vehicle.h"

namespace sdds {
	const int MAX_NUM_PARKING_SPOT = 100; //Maximum number of parking spots
	class Parking: public Menu {
		char* m_dfname; //name of the data file
		int m_numspots; // number of parking spots always lower than MAX_NUM_PARKING_SPOT
		Vehicle* m_parkspots[MAX_NUM_PARKING_SPOT];
		int m_numparkvehicles; //Number of Parked Vehicles always less than number of spots
		Menu ParkingMenu; //stores information of the parking menu, populated if loadData is true
		Menu VehicleMenu; //stores information on the vehicle menu, populated if loadData is true
	public:
		Parking(const char* fn, int noOfSpots); //custom constructor of parking class taking data from .csv file
		~Parking(); //destructor of parking class
		Parking(const Parking& src) = delete; //copy function prohibited
		Parking& operator=(const Parking& src) = delete; //copy assignment prohibited
		int run(); //runs the whole application
	private:
		bool isEmpty(); //returns true if parking is in an empty state, false otherwise
		void ParkingStatus(); //Prints: "****** Seneca Valet Parking ******"<NEWLINE>
		void ParkVehicle(); //Prints selection of parking
		void returnVehicle(); //Prints: "Returning Vehicle" <NEWLINE>
		void listParkedVehicle(); //Prints: "Listing Parked Vehicles" <NEWLINE>
		bool closePark(); //Prints: "Closing Parking" and return true
		bool exitParking(); //Prints: "This will terminate the program!"<NEW LINE> "Are you sure? (Y)es/(N)o: ". Y == true, N == false 
		bool loadDataF(); //If empty state, return false, otherwise print "loading data from " file name and return true
		void saveDataF(); //If non-empty state, print "Saving data into " data file
		void setParking(const char cm); //sets vehicle according to either c(car) or m(motorcycle)
	};
}

#endif