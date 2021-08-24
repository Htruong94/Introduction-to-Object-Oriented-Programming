/* Citation and Sources...
Final Project Milestone 6
Module: Parking
Filename: Parking.cpp
Version 1.2
Author Hung Truong - 147779193
Revision History
-----------------------------------------------------------
Date Reason
2020/7/16 Prelimary Release
2020/7/26 Rework parking functions for milestone 6
2020/7/30 Altered to address bugs found while submission
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
#include <iomanip>
#include <fstream>
#include "Parking.h"
#include "Utils.h"
#include "Car.h"
#include "Motorcycle.h"

using namespace sdds;


Parking::Parking(const char* fn, int noOfSpots) {
	m_dfname = nullptr; //signifies that the class is in an empty state
	m_numspots = 0;
	m_numparkvehicles = 0;

	for (int i = 0; i < MAX_NUM_PARKING_SPOT; i++) {
		m_parkspots[i] = nullptr;
	}

	if ((fn != nullptr && fn[0] != '\0') || (noOfSpots >= 10 && noOfSpots <= MAX_NUM_PARKING_SPOT)) {
		m_dfname = new char[wordLength(fn) + 1];
		for (int i = 0; i <= wordLength(fn); i++) {
			m_dfname[i] = fn[i];
		}
		m_numspots = noOfSpots;
	}

	if (!loadDataF()) { //returns error if file is not open
		std::cout << "Error in data file" << std::endl;
	}

	Menu ParkingMenuTemp("Parking Menu, select an action:"); //Populating Parking Menu
	ParkingMenu = ParkingMenuTemp;
	ParkingMenu << "Park Vehicle" << "Return Vehicle" << "List Parked Vehicles" << "Close Parking (End of day)" << "Exit Program";
	Menu VehicleMenuTemp("Select type of the vehicle:", 1); //Populating Vehicle Selection Menu
	VehicleMenu = VehicleMenuTemp;
	VehicleMenu << "Car" << "Motorcycle" << "Cancel";
}

Parking::~Parking() {
	saveDataF();
	delete[] m_dfname;
	m_dfname = nullptr;
	for (int i = 0; i <= m_numspots; i++) {
		if (m_parkspots[i] != nullptr) {
			delete m_parkspots[i];
			m_parkspots[i] = nullptr;
		}
	}
}

int Parking::run() {
	int selection = -1;
	bool exit = false;
	if (!isEmpty()) {
		while(!exit) {
			ParkingStatus();
			ParkingMenu.display();
			selection = getInt(1, 5); 
			if (selection == 1) { //function called is determined by the selection of the user
				ParkVehicle();
			}
			else if (selection == 2) {
				returnVehicle();
			}
			else if (selection == 3) {
				listParkedVehicle();
			}
			else if (selection == 4) {
				exit = closePark();
			}
			else {
				exit = exitParking();
				if (exit) {
					std::cout << "Exiting program!" << std::endl;
				}
			}
		}
	}
	return selection;
}

bool Parking::isEmpty() {
	if (m_dfname != nullptr) { 
		return false;
	}
	else {
		return true;
	}
}

void Parking::ParkingStatus() {
	std::cout << "****** Seneca Valet Parking ******" << std::endl;
	std::cout << "*****  Available spots: " << std::setw(4) << std::left << m_numspots - m_numparkvehicles << " *****" << std::endl;
}

void Parking::ParkVehicle() {
	int selection = -1;
	if (m_numparkvehicles < m_numspots) {
		VehicleMenu.display();
		selection = getInt(1, 3);
		if (selection == 1) {
			setParking('c');
		}
		else if (selection == 2) {
			setParking('m');
		}
		else {
			std::cout << "Parking cancelled" << std::endl;
		}
	}
	else {
		std::cout << "Parking is full" << std::endl;
	}
}

void Parking::returnVehicle() {
	int match = -1; //initialize outside of range, stores element number if match is found
	char license[20] = { '\0' }; //store use input license
	std::cout << "Return Vehicle" << std::endl;
	std::cout << "Enter Licence Plate Number: ";
	std::cin >> license;
	std::cin.ignore(2000, '\n');
	std::cin.clear();
	while (wordLength(license) > MAX_LP_NUM_LEN || license == nullptr) {
		std::cout << "Invalid Licence Plate, try again: ";
		std::cin >> license;
		std::cin.ignore(2000, '\n');
		std::cin.clear();
	}
	for (int i = 0; license[i] != '\0'; i++) { //make input to all capital
		if (license[i] >= 'a' && license[i] <= 'z') {
			license[i] += ('A' - 'a');
		}
	}
	for (int i = 0; i < m_numspots; i++) {
		if (m_parkspots[i] != nullptr) {
			if (*m_parkspots[i] == license) {
				match = i;
			}
		}
	}
	if (match == -1) {
		std::cout << "License plate: " << license << " Not found" << std::endl;
	}
	else {
		std::cout << std::endl << "Returning: " << std::endl;
		std::cout << *m_parkspots[match] << std::endl;
		delete m_parkspots[match];
		m_parkspots[match] = nullptr;
		m_numparkvehicles--;
	}
}

void Parking::listParkedVehicle() {
	std::cout << "*** List of parked vehicles ***" << std::endl;
	for (int i = 0; i < m_numspots; i++) {
		if (m_parkspots[i] != nullptr) {
			std::cout << *m_parkspots[i];
			std::cout << "-------------------------------" << std::endl;
		}
	}
}

bool Parking::closePark() {
	bool empty = true;
	char yn = ' ';

	for (int i = 0; i < m_numspots; i++){
		if (m_parkspots[i] != nullptr) {
			empty = false;
		}
	}
	if (empty) {
		std::cout << "Closing Parking" << std::endl;
		return true;
	}
	else {
		std::cout << "This will Remove and tow all remaining vehicles from the parking!" << std::endl;
		std::cout << "Are you sure? (Y)es/(N)o: ";
		yn = yesNo();
		if (yn == 'N' || yn == 'n') {
			std::cout << "Aborted!" << std::endl;
			return false;
		}
		else {
			std::cout << "Closing Parking" <<std::endl;
			for (int i = 0; i < m_numspots; i++) {
				if (m_parkspots[i] != nullptr) {
					std::cout << std::endl << "Towing request" << std::endl;
					std::cout << "*********************" << std::endl;
					std::cout << *m_parkspots[i];
					delete m_parkspots[i];
					m_parkspots[i] = nullptr;
				}
			}
			return true;
		}
	}
}

bool Parking::exitParking() {
	char choice = ' '; //takes up to 16 characters, initialize choice
	std::cout << "This will terminate the program!" <<std::endl;
	std::cout << "Are you sure? (Y)es/(N)o: ";
	choice = yesNo();
	if (choice == 'Y' || choice == 'y') {
		return true;
	}
	else {
		return false;
	}
}

bool Parking::loadDataF() {

	char CM =' ';
	char license[256] = { '\0' };
	char makemodel[256] = { '\0' };
	int parkspot = 0;
	bool SCorCW = false; //side car or car wash boolean

	for (int i = 0; i < MAX_NUM_PARKING_SPOT; i++) {
		m_parkspots[i] = nullptr;
	}

	if (isEmpty()) {
		return false;
	}
	else {
		std::ifstream fin;
		fin.open(m_dfname);
		if (fin.is_open()) {
			while (fin) {
				fin >> CM;
				if (CM != ' ') {
					fin.ignore(1, ',');
					fin >> parkspot;
					fin.ignore(1, ',');
					fin.getline(license, 9, ',');
					fin.getline(makemodel, 60, ',');						
					fin >> SCorCW;

					//test statement below
					//std::cout << CM << ", " << parkspot << ", " << license << ", " << makemodel << ", " << SCorCW << std::endl;

					if (CM == 'C') {
						m_parkspots[m_numparkvehicles] = new Car(license, makemodel, SCorCW);						
					}
					else {
						m_parkspots[m_numparkvehicles] = new Motorcycle(license, makemodel, SCorCW);
					}
					m_parkspots[m_numparkvehicles]->setCsv(false);
					m_parkspots[m_numparkvehicles]->setParkingSpot(parkspot);
					m_numparkvehicles++;

					license[0] = '\0';
					makemodel[0] = '\0';
					SCorCW = false;
					CM = ' ';
					parkspot = 0;
				}
			}
			fin.close();
			
			return true;
		}
		else {
			return false;
		}
	}
}

void Parking::saveDataF() {
	if (!isEmpty()) {
		std::ofstream fout(m_dfname);
		if (fout.is_open()) {
			for (int a = 0; a < MAX_NUM_PARKING_SPOT; a++) {
				if (m_parkspots[a] != nullptr) {
					m_parkspots[a]->setCsv(true);
					fout << *m_parkspots[a];
				}
			}
			fout.close();
		}
	}
	else {
		std::cerr << "File not open" << std::endl;
	}
}

void Parking::setParking(const char cm) {
	int elementempty = 0;
	bool set = false;
	if (m_numparkvehicles <= m_numspots) {

		m_numparkvehicles++;

		for (int i = 0; set == false; i++) {
			if (m_parkspots[i] == nullptr) {
				elementempty = i;
				set = true;
			}
		}

		delete m_parkspots[elementempty];

		if (cm == 'c') {
			m_parkspots[elementempty] = new Car();
		}
		else {
			m_parkspots[elementempty] = new Motorcycle();
		}

		m_parkspots[elementempty]->setParkingSpot(elementempty + 1);
		m_parkspots[elementempty]->setCsv(false);

		std::cin >> *m_parkspots[elementempty];

		std::cout << std::endl << "Parking Ticket" << std::endl;
		std::cout << *m_parkspots[elementempty] << std::endl;
	}
}
