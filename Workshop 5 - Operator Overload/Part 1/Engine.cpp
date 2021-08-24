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
#include "Engine.h"

using namespace std;
using namespace sdds;

Engine::Engine() { //default constructor: initialize the engine class
	m_size = 0;
	m_type[0] = '\0';
}

Engine::Engine(const char* type, double size) { //custom constructor: set values for engine class
	m_size = 0;
	m_type[0] = '\0';

	if (type[0] != '\0' && size > 0) {
		for (int i = 0; i < TYPE_MAX_SIZE; i++) {
			m_type[i] = type[i];
		}
		m_size = size;
	}
}

double Engine::get() const { //returns the value of m_size for the engine class
	return m_size;
}

void Engine::display() const { //displays the engine's information
	cout << m_size << " liters - " << m_type << endl;
}