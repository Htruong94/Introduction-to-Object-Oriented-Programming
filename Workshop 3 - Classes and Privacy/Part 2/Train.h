//==============================================
// Name:           Hung Truong
// Student Number: 147779193
// Email:          htruong19@myseneca.ca
// Section:        NAA
// Date:           June 9, 2020 
//==============================================
// Workshop:       3
// Part:           1
//==============================================

#ifndef TRAIN_H
#define TRAIN_H

#include "Cargo.h"

namespace sdds {
	const int MAX_NAME = 30;

	class Train {
		char t_Name[MAX_NAME]; //stores name of train
		int t_ID; //Greater than 0
		Cargo* t_Cargo; //loads cargo information into train
	public:
		void initialize(const char* name, int id);
		bool isValid() const;
		void loadCargo(Cargo car);
		void unloadCargo();
		void display() const;
	};
}

#endif