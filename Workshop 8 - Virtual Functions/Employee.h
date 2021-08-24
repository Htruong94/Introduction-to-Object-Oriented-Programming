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

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>

namespace sdds {
	class Employee { //assume all parameters given are valid
		const int m_minhours = 0; //const minimum number of hours employee must work in a week
		double m_hourlysalary; //hourly salary value of the employee
	public:
		Employee(int minhours, double hourlysalary); // default constructor of Employee class
		virtual double getSalary(int workedHours) = 0; //pure virtual query to calculate salary of the employeee in a week
		virtual std::ostream& display(std::ostream& out = std::cout) = 0; //pure virtual query which prints data according to the employee type
		virtual ~Employee() {}; //virtual empty destructor
	protected:
		int getMinHours(); //retrieves the minimum working hours value
		double getHourlySalary(); //retrieves the hourly salary
	};

	std::ostream& operator << (std::ostream& out, Employee& src);  //helper function to the display function
}

#endif