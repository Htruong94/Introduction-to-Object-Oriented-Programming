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

#include <iostream>
#include <iomanip>	
#include "Train.h"
#include "Cargo.h"

using namespace sdds;
using namespace std;

void Train::initialize(const char* name, int id) { //initialize the given train class
	t_Name[0] = '\0';
	t_ID = 0;
	t_Cargo = nullptr;
	if (id > 0 && name != nullptr) {
		t_ID = id;
		for (int i = 0; i < MAX_NAME;i++) {
			t_Name[i] = name[i];
		}
	}
}

bool Train::isValid() const { //Check if the given train class has information 
	if (t_Name[0] == '\0') {
		return false;
	}
	else {
		return true;
	}
}

void Train::loadCargo(Cargo car) { //Puts cargo information into a given train class
	if (t_Cargo == nullptr) { 
		t_Cargo = new Cargo;
	}

	for (int i = 0; i < MAX_DESC; i++) {
		t_Cargo->c_Desc[i] = car.c_Desc[i];
	}

	t_Cargo->c_Weight = car.c_Weight;
}

void Train::unloadCargo() { //deletes cargo information inside given train class
	delete t_Cargo;
	t_Cargo = nullptr;
}

void Train::display() const { //displays a summary of the information inside the given train class
	cout << "***Train Summary***" << endl;
	if (t_Name[0] == '\0') {
		cout << "This is an invalid train." << endl;
	}
	else if (t_Cargo == nullptr) {
		cout << "Name: " << t_Name << endl;
		cout << "ID: " << t_ID << endl;
		cout << "No cargo on this train." << endl;
	}
	else {
		cout << "Name: " << t_Name << endl;
		cout << "ID: " << t_ID << endl;
		cout << "Cargo: " << t_Cargo->c_Desc << endl;
		cout << "Weight: " << t_Cargo->c_Weight << endl;
	}
}