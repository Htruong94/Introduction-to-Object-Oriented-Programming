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
#include <iomanip>
#include "Engineer.h"

using namespace sdds;

Engineer::Engineer(double hourlysalary, int lvl): Employee(30, hourlysalary) { //employee must work a minimum of 30 hours a week
	m_lvl = 0;
	m_lvl = lvl;
}

double Engineer::getSalary(int workedHours) {
	double salary = 0; 

	salary = ((double)workedHours * (double)getHourlySalary()) + (m_lvl * (double)40);

	if (workedHours <= getMinHours()) {
		salary *= 0.8; //20% cut to salary for working less than minimum
	}

	return salary;
}

std::ostream& Engineer::display(std::ostream& out = std::cout){
	out << "Engineer" << std::endl;
	out << std::setw(20) << std::right << "Level: " << m_lvl << std::endl;
	out << std::setw(20) << std::right << "Pay Rate: " << getHourlySalary() << std::endl;
	out << std::setw(20) << std::right << "Min Hours: " << getMinHours() << std::endl;

	return out;
}