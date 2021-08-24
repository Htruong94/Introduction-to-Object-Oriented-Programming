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

#ifndef ENGINEER_H
#define ENGINEER_H

#include "Employee.h"

namespace sdds {
	class Engineer :public Employee {
		int m_lvl; //level of engineer which affects salary
	public:
		Engineer(double hourlysalary, int lvl); //custom constructor of engineer class
		double getSalary(int workedHours); //getSalary override calculating salary based on engineer rules
		std::ostream& display(std::ostream& out); //display override inserting engineer data into stream
	};
}

#endif