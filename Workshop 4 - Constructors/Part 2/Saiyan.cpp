//==============================================
// Name:           Hung Truong
// Student Number: 147779193
// Email:          htruong19@myseneca.ca
// Section:        NAA
// Date:           June 18, 2020 
//==============================================
// Workshop:       4
// Part:           2
//==============================================

#include <iostream>
#include "Saiyan.h"

using namespace std;
using namespace sdds;

Saiyan::Saiyan() { //default constructor, initialize the saiyan class when called to empty state
	m_name = nullptr;
	m_dob = defaultVal;
	m_power = defaultVal;
	m_super = defaultBool;
	m_level = defaultVal;
}

Saiyan::Saiyan(const char* name, int dob, int power, int level, bool Super) { //custom constructor, takes input from call and set it to the class if parameters are valid
	m_name = nullptr;
	set(name, dob, power, level, Super);
}

void Saiyan::set(const char* name, int dob, int power, int level, bool Super) { //checks if all parameters are valid, then sets to class, otherwise set to initialize values
	int nameLen = 0;
	if (name != nullptr) {
		while (name[nameLen] != '\0' || nameLen == MAXNAMELEN) {
			nameLen++;
		}
	}
	if (nameLen > 0 && dob <= 2020 && power >= 0 && level >= 0) {

		delete[] m_name;
		m_name = new char[nameLen + 1];

		for (int i = 0; i <= nameLen; i++) {
			m_name[i] = name[i];
		}

		m_dob = dob;
		m_power = power;
		m_super = Super;
		m_level = level;
	}

	else { //sets to empty state
		m_name = nullptr;
		m_dob = defaultVal;
		m_power = defaultVal;
			m_super = defaultBool;
		m_level = defaultVal;
	}
}

bool Saiyan::isValid() const { //check if the saiyan is in memory
	if (m_name != nullptr) {
		return true;
	}
	else {
		return false;
	}
}

void Saiyan::display() const { //displays information of the called saiyan
	if (isValid()) {
		cout << m_name << endl;
		cout << "     DOB: " << m_dob << endl;
		cout << "   Power: " << m_power << endl;
		if (m_super) {
			cout << "   Super: yes" << endl;
			cout << "   Level: " << m_level << endl;
		}
		else {
			cout << "   Super: no" << endl;
		}
	}
	else {
		cout << "Invalid Saiyan!" << endl;
	}
}

bool Saiyan::fight(Saiyan& other) { //sees which saiyan has the higher power if both saiyans are valid
	if (isValid() && other.isValid()) {
		if (m_super) {
			m_power += (0.1 * m_power * m_level);
		}
		if (other.m_super) {
			other.m_power += (0.1 * other.m_power * other.m_level);
		}

		if (m_power > other.m_power) {
			return true;
		}
		else {
			return false;
		}

	}
	else {
		return false;
	}
}

Saiyan::~Saiyan() { //deletes the saiyan class at the end of use
	delete[] m_name;
	m_name = nullptr;
}
