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

#ifndef DOCTOR_H
#define DOCTOR_H

#include "Employee.h"

namespace sdds {
	class Doctor: public Employee {
		char m_type[32]; //holds a c-string that contains the type of doctor
		bool m_specialist; //If the doctor is a specialist, this is true, else is false
	public:
		Doctor(const char* type, double salary, int minhours, bool specalist = false); //custom constructor of doctor class
		double getSalary(int workedHours); //getSalary override, calculates salary with doctor rules
		std::ostream& display(std::ostream& out); //display override, insert to stream doctor data
	};
}

#endif