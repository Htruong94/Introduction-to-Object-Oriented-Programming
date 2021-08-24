/* Citation and Sources...
Final Project Milestone 6
Module: Vehicle
Filename: Vehicle.cpp
Version 1.1
Author Hung Truong - 147779193
Revision History
-----------------------------------------------------------
Date Reason
July 23, 2020 - Initial Release
July 25, 2020 - Fixed Input error found in milestone 5
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/
#include "Vehicle.h"
#include "Utils.h"

using namespace sdds;

//Public Constructors
Vehicle::Vehicle() {
	//std::cout << "Default Constructor Vehicle" << std::endl;
	m_license[0] = '\0'; //empty state of vehicle class
	m_parkspotnum = 0; //default spot number
	//default makemodel to a char string of size 2 as cannot be null/empty
	m_makemodel = nullptr;
}

Vehicle::Vehicle(const char* license, const char* makemodel, int parkspotnum) {
	//std::cout << std::endl << "Custom Constructor Vehicle" << std::endl;
	char temp[8] = { '\0' };
	int i = 0;

	//initializing class variables
	m_parkspotnum = parkspotnum;
	for (int a = 0; a <= MAX_LP_NUM_LEN; a++) {
		m_license[a] = '\0';
	}
	
	m_makemodel = nullptr;
	if ((license != nullptr && license[0] != '\0' && wordLength(license) <= MAX_LP_NUM_LEN) && (makemodel != nullptr && makemodel[0] != '\0' && makemodel[1] != '\0')) {
		for (i = 0; license[i] != '\0'; i++) { //make input to all capital
			if (license[i] >= 'a' && license[i] <= 'z') {
				temp[i] = license[i] + ('A' - 'a');
			}
			else {
				temp[i] = license[i];
			}
		}
		
		strCpy(m_license, temp);
		m_license[i] = '\0';
		delete [] m_makemodel;
		m_makemodel = new char[wordLength(makemodel) + 1];

		strCpy(m_makemodel, makemodel);
	}
}

Vehicle::~Vehicle() {
	if (m_makemodel != nullptr) {
		delete[] m_makemodel;
	}
}

//Public Member Functions

int Vehicle::getParkingSpot() const {
	return m_parkspotnum;
}

void Vehicle::setParkingSpot(int parkspot) {
	if (parkspot >= 0) { //check for valid parkspot number
		m_parkspotnum = parkspot;
	}
	else {
		m_license[0] ='\0';
	}
}

bool Vehicle::operator==(const char* license) const{
	int valid=0;
	char temp[MAX_LP_NUM_LEN] = { '\0' };
	for (int i = 0; license[i] != '\0'; i++) { //make input to all capital
		if (license[i] >= 'a' && license[i] <= 'z') {
			temp[i] = license[i] + ('A' - 'a');
		}
		else {
			temp[i] = license[i];
		}
	}

	valid = strCmp(m_license, temp);
	if (valid == 0){ //if license matches, return true, else false
		return true;
	}
	else {
		return false;
	}
}

bool Vehicle::operator==(const Vehicle& src) const{
	if (*this == src.m_license) { //call object to cstring comparison
		return true;
	}
	else {
		return false;
	}
}

std::istream& Vehicle::read(std::istream& istr) {
	char license[10] = { '\0' }; //store string slightly larger of size of m_license
	char makemode[60] = { '\0' };

	if (this->isCsv()) { //comma seperated value mode
		istr >> m_parkspotnum;
		istr.ignore(1, ',');
		istr.getline(license, 10, ',');
		istr.getline(makemode, 60, ',');
	}
	else { //non-comma seperated value mode
		std::cout << "Enter Licence Plate Number: ";
		istr.getline(license, 10, '\n');
		istr.clear();
		while((wordLength(license) > MAX_LP_NUM_LEN || wordLength(license) <= 0) || license == nullptr) {
			std::cout << "Invalid Licence Plate, try again: ";
			istr.getline(license, 10, '\n');
			istr.clear();
		}

		std::cout << "Enter Make and Model: "; 
		istr.getline(makemode, 60, '\n');
		istr.clear();

		while (makemode[1] == '\0' || makemode == nullptr) {
			std::cout << "Invalid Make and model, try again: ";
			istr.getline(makemode, 60, '\n');
			istr.clear();
		}
	}
	for (int i = 0; license[i] != '\0'; i++) { //make input to all capital
		if (license[i] >= 'a' && license[i] <= 'z') {
			license[i] += ('A' - 'a');
		}
	}

	m_license[0] =  '\0';
	strCpy(m_license, license);
	setMakeModel(makemode);
	license[0] = '\0';
	return istr;
}

std::ostream& Vehicle::write(std::ostream& ostr) const {
	if (isEmpty()) {
		ostr << "Invalid Vehicle Object" << std::endl;
	}
	else if (isCsv()) {
		ostr << m_parkspotnum << "," << m_license << "," << m_makemodel << ",";
	}
	else {
		ostr << "Parking Spot Number: ";
		if (m_parkspotnum == 0) {
			ostr << "N/A" << std::endl;
		}
		else {
			ostr << m_parkspotnum << std::endl;
		}
		ostr << "Licence Plate: " << m_license << std::endl;
		ostr << "Make and Model: " << m_makemodel << std::endl;
	}

	return ostr;
}

void Vehicle::strCpy(char* dest, const char* cpy) {
	for (int i = 0; i <= wordLength(cpy); i++) {
		dest[i] = cpy[i];
	}
}

//Protected function

void Vehicle::setEmpty() {
	m_license[0] = '\0'; //invalid empty state
}

bool Vehicle::isEmpty() const {
	if (m_license[0] == '\0') {
		return true;
	}
	else {
		return false;
	}
}

const char* Vehicle::getLicensePlate(){
	return m_license;
}

const char* Vehicle::getMakeModel(){
	return m_makemodel;
}

void Vehicle::setMakeModel(const char* makemodel) {
	if (makemodel != nullptr && makemodel[0] != '\0') {
		if (m_makemodel != nullptr) {
			delete [] m_makemodel;
			m_makemodel = nullptr;
		}
		m_makemodel = new char[wordLength(makemodel)+1];
		
		strCpy(m_makemodel, makemodel);
	}
	else { //set to empty state if above is not true
		m_license[0] = '\0';
	}
}