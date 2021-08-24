//==============================================
// Name:           Hung Truong
// Student Number: 147779193
// Email:          htruong19@myseneca.ca
// Section:        NAA
// Date:           June 23, 2020
//==============================================
// Workshop:       5
// Part:           1
//==============================================

#include <iostream>
#include "Ship.h"

using namespace std;
using namespace sdds;

Ship::Ship() { //default constructor: initialize Ship class
	m_type[0] = '\0';
	m_engCnt = 0;
}

Ship::Ship(const char* type, Engine* engines, int engCnt) { //Custom constructor: set values for Ship Class
	m_type[0] = '\0';
	m_engCnt = 0;

	if (type[0] != '\0' && engCnt > 0) {
		for (int i = 0; i < TYPE_MAX_SIZE; i++) {
			m_type[i] = type[i];
		}
		for (int i = 0; i < engCnt; i++) {
			m_engines[i] = engines[i];
		}
		m_engCnt = engCnt;
	}

}

Ship::operator bool() const { //returns true if the ship is valid by looking if ship type is not empty
	bool valid = m_type[0] != '\0';
	return valid;
}

double Ship::m_power() const{ //returns the total power of the ship
	double power = 0;
	for (int i = 0; i < m_engCnt; i++) {
		power += m_engines[i].get();
	}

	return power * 5;
}

Ship& Ship::operator+=(Engine engine) { //adds input engine to the desired ship class if the ship is valid and has an engine count that is not 10

	if (m_type[0] == '\0' || m_engCnt == 10) {
		cout << "The object is not valid! Engine cannot be added!" << endl;
	}
	else {
		m_engines[m_engCnt] = Engine(); //initializes engine
		m_engines[m_engCnt] = engine;
		m_engCnt++; //number of engines increases
	}
	return *this;
}

bool Ship::operator<(double power) const { //checks if the ship power is less than the input power
	return (m_power() < power);
}

void Ship::display() const { //displays the information of the ship with the engine information
	if (m_type[0] == '\0') {
		cout << "No available data" << endl;
	}
	else {
		cout << m_type << " - " << m_power() << endl;
		for (int i = 0; i < m_engCnt; i++) {
			m_engines[i].display();
		}
	}
}

bool sdds::operator<(double power, const Ship& theShip) { //check if the input power is less than the ship power
	return !(theShip.operator<(power));
}