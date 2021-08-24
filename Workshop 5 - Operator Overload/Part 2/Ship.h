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
#include "Engine.h"
#ifndef SHIP_H
#define SHIP_H

namespace sdds {
	const double MIN_STD_POWER = 90.111;
	const double MAX_STD_POWER = 99.999;

	class Ship {
		Engine *m_engines; //max capacity of 10 engines
		char m_type[TYPE_MAX_SIZE]; //ship model type of size TYPE_MAX_SIZE
		int m_engCnt; //number of engines installed
		double m_power() const; //total power of the ship according to total engine size * 5
	public:
		Ship();
		Ship(const char* type, Engine* engines, int engCnt);
		explicit operator bool() const;
		Ship& operator+=(Engine engine);
		bool operator<(double power) const;
		void display() const;
		~Ship();
	};

	bool operator<(double power, const Ship& theShip);
};


#endif