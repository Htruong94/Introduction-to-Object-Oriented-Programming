//==============================================
// Name:           Hung Truong
// Student Number: 147779193
// Email:          htruong19@myseneca.ca
// Section:        NAA
// Date:           June 16, 2020 
//==============================================
// Workshop:       4
// Part:           1
//==============================================

#include <iostream>
#include "Saiyan.h"

using namespace std;
using namespace sdds;

Saiyan::Saiyan() { //default constructor, initialize the saiyan class when called to empty state
	m_name[0] = defaultChar;
	m_dob = defaultVal;
	m_power = defaultVal;
	m_super = defaultBool;
}

Saiyan::Saiyan(const char* name, int dob, int power) { //custom constructor, takes input from call and set it to the class if parameters are valid
	set(name, dob, power, false);
}

void Saiyan::set(const char* name, int dob, int power, bool Super) { //checks if all parameters are valid, then sets to class, otherwise set to initialize values
	if (name != nullptr && dob <= 2020 && power >= 0) {
		for (int i = 0; i < MAXNAMELEN; i++) {
			m_name[i] = name[i];
		}
		m_dob = dob;
		m_power = power;
		m_super = Super;
	}
	else { //sets to empty state
		m_name[0] = defaultChar;
		m_dob = defaultVal;
		m_power = defaultVal;
		m_super = defaultBool;
	}
}

bool Saiyan::isValid() const { //check if the saiyan is in memory
	if (m_name[0] != '\0') {
		return true;
	}
	else {
		return false;
	}
}

void Saiyan::display() const { //displays information of the called saiyan
	if (isValid()) {
		cout << m_name << endl;
		cout << "DOB: " << m_dob << endl;
		cout << "Power: " << m_power << endl;
		if (m_super) {
			cout << "Super: yes" << endl;
		}
		else {
			cout << "Super: no" << endl;
		}
	}
	else {
		cout << "Invalid Saiyan!" << endl;
	}
}

bool Saiyan::fight(const Saiyan& other) const { //sees which saiyan has the higher power if both saiyans are valid
	if (isValid() && other.isValid()) {
		if (m_power > other.m_power) {
			return true;
		}
		else
			return false;
	}
	else {
		return false;
	}
}

