//==============================================
// Name:           Hung Truong
// Student Number: 147779193
// Email:          htruong19@myseneca.ca
// Section:        NAA
// Date:           June 27, 2020
//==============================================
// Workshop:       5
// Part:           2
//==============================================

#include <iostream>
#include <iomanip>	
#include "Ship.h"

using namespace std;
using namespace sdds;

Ship::Ship() { //default constructor: initialize Ship class
	m_type[0] = '\0';
	m_engCnt = 0;
	m_engines = nullptr;
}

Ship::Ship(const char* type, Engine* engines, int engCnt) { //Custom constructor: set values for Ship Class
	m_type[0] = '\0';
	m_engCnt = 0;
	m_engines = nullptr;

	if (type[0] != '\0' && engCnt > 0) {
		for (int i = 0; i < TYPE_MAX_SIZE; i++) {
			m_type[i] = type[i];
		}
		m_engCnt = engCnt;
		m_engines = new Engine[m_engCnt];
		for (int i = 0; i < engCnt; i++) {
			m_engines[i] = engines[i];
		}
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
	Engine* temp; //temp ship to hold engines of the class given

	if (m_type[0] == '\0' || m_engCnt == 10) {
		cout << "The object is not valid! Engine cannot be added!" << endl;
	}
	else {
		m_engCnt++; //number of engines increases

		temp = nullptr;
		temp = new Engine[m_engCnt]; //dynamically allocate the temp engines to the new engine count size
	
		for (int i = 0; i < m_engCnt - 1; i++) { //copy engines from the given ship class and store in temp class
			temp[i] = m_engines[i];
		}

		delete[] m_engines; //deallocate engines in given ship class
		m_engines = nullptr;
		m_engines = new Engine[m_engCnt]; //dynamically allocate the ship class with the new engine count size

		for (int i = 0; i < m_engCnt - 1; i++) { //copy the stored temp engines back to the given ship class
			m_engines[i] = temp[i];
		}

		m_engines[m_engCnt-1] = engine;

		delete[] temp; //deallocate temp engine
		temp = nullptr;
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
		cout.setf(ios::fixed); 
		cout.precision(2); //set precision to 2 decimal places
		cout << m_type << " - ";
		cout.width(6);
		cout << m_power() << endl;
		for (int i = 0; i < m_engCnt; i++) {
			m_engines[i].display();
		}
		cout.unsetf(ios::fixed);
		cout.precision(6); //reset precision to default 6.
	}
}

Ship::~Ship() { //destructor of Ship class
	delete[] m_engines;
	m_engines = nullptr;
}

bool sdds::operator<(double power, const Ship& theShip) { //check if the input power is less than the ship power
	return !(theShip.operator<(power));
}