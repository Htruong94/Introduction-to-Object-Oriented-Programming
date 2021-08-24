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

#include "Truck.h"
using namespace sdds;

Truck::Truck(const char* lpNum, int yearBuilt, double capacity, const char* address, double cargoload) : MotorVehicle(lpNum, yearBuilt) {
	m_capacity = 0;
	m_cargoLoad = cargoload;
	moveTo(address);

	m_capacity = capacity;
}

bool Truck::addCargo(double cargo) {
	if (m_cargoLoad < m_capacity) {
		m_cargoLoad += cargo;
		if (m_cargoLoad > m_capacity) { //if cargo exceeds capacity, cargo is set to capacity instead
			m_cargoLoad = m_capacity;
		}
		return true;
	}
	else {
		return false;
	}
}

bool Truck::unloadCargo() {
	if (m_cargoLoad != 0) {
		m_cargoLoad = 0;
		return true;
	}
	else {
		return false;
	}
}

std::ostream& Truck::write(std::ostream& os) const{
	MotorVehicle::write(os);
	os << " | " << m_cargoLoad << "/" << m_capacity;

	return os;
}

std::istream& Truck::read(std::istream& in) {
	MotorVehicle::read(std::cin);

	std::cout << "Capacity: ";
	in >> m_capacity;
	std::cout << "Cargo: ";
	in >> m_cargoLoad;

	return in;
}

std::ostream& sdds::operator<<(std::ostream& os, const Truck& src) {
	src.write(os);
	return os;
}

std::istream& sdds::operator>>(std::istream& in, Truck& src) {
	src.read(in);

	return in;
}