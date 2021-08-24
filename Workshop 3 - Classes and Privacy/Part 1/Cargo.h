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

#ifndef CARGO_H
#define CARGO_H

namespace sdds {
	const int MAX_DESC = 20;
	
	struct Cargo {
		char c_Desc[MAX_DESC];
		float c_Weight;
	};
}

#endif