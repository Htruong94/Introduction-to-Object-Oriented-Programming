//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

//==============================================
// Name:           Hung Truong
// Student Number: 147779193
// Email:          htruong19@myseneca.ca
// Section:        NAA
// Date:           July 20, 2020
//==============================================
// Workshop:       8
//==============================================
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iomanip>
#include "Doctor.h"

using namespace sdds;

Doctor::Doctor(const char* type, double salary, int minhours, bool specalist) :Employee(minhours, salary) {
	m_type[0] = '\0';

	strcpy(m_type, type);

	m_specialist = specalist;
}

double Doctor::getSalary(int workedHours) {
	double salary = 0;

	if (workedHours <= getMinHours()) { //normal pay if less or equal to minimum work hours
		salary = workedHours * getHourlySalary();
	}
	else { //bonus for every hour worked passed minimum hours by a multiple of x1.5
		salary = ((double)getMinHours() + (((double)workedHours- (double) getMinHours())*1.5)) * getHourlySalary();
	}

	if (m_specialist) { //bonus $2000 if the doctor is a specialist
		salary += 2000;
	}

	return salary;
}

std::ostream& Doctor::display(std::ostream& out = std::cout){

	out << "Doctor" << std::endl;

	out << std::setw(16) << std::right << "Type: " << m_type;
	if (m_specialist) {
		out << " (specialist)";
	}
	out << std::endl << std::setw(16) << std::right << "Pay Rate: " << getHourlySalary() << std::endl;
	out << std::setw(16) << std::right << "Min Hours: " << getMinHours() << std::endl;

	return out;
}
