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

#define _CRT_SECURE_NO_WARNINGS
#include "MotorVehicle.h"
#include <iomanip>
#include <cstring>
using namespace sdds;

MotorVehicle::MotorVehicle(const char *LPnum, int caryear, const char* addDefault) { //assume all data is valid
	//initializing class
	m_LPnum[0] = '\0';
	m_vehAdd[0] = '\0';
	m_carYear = 0;

	strcpy(m_LPnum, LPnum);
	strcpy(m_vehAdd, addDefault);
	m_carYear = caryear;
	
	//std::cout << m_LPnum << " " << m_vehAdd << " " << m_carYear << std::endl;
}

void MotorVehicle::moveTo(const char* address) {
	if (address != m_vehAdd) {
		std::cout << "|" << std::setw(10) << std::right << m_LPnum; 
		std::cout << "| |" << std::setw(20) << std::right << m_vehAdd;
		std::cout << " --->--- " << std::setw(20) << std::left << address << "|" << std::endl;
		m_vehAdd[0] = '\0';
		strcpy(m_vehAdd, address);
	}
}

std::ostream& MotorVehicle::write(std::ostream& os) const{
	os << "| " << m_carYear;
	os << " | " << m_LPnum;
	os << " | " << m_vehAdd;
	return os;
}

std::istream& MotorVehicle::read(std::istream& in) {
	
	std::cout << "Built year: ";
	in >> m_carYear;
	std::cout << "License plate: ";
	in >> m_LPnum;
	std::cout << "Current location: ";
	in >> m_vehAdd;

	return in;
}

std::ostream& sdds::operator<< (std::ostream& os, const MotorVehicle& src) {
	src.write(os);
	return os;
}

std::istream& sdds::operator>> (std::istream& in, MotorVehicle& src) {
	src.read(in);
	return in;
}