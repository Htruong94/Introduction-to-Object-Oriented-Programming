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

#include "Employee.h"

using namespace sdds;

Employee::Employee(int minhours, double hourlysalary) : m_minhours(minhours) {
	m_hourlysalary = hourlysalary;
}

int Employee::getMinHours() {
	return m_minhours;
}

double Employee::getHourlySalary() {
	return m_hourlysalary;
}

std::ostream& sdds::operator << (std::ostream& out, Employee& src) {
	src.display(out);
	return out;
}