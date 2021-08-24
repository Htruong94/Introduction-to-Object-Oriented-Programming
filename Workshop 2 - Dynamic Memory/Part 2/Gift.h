//==============================================
// Name:           Hung Truong
// Student Number: 147779193
// Email:          htruong19@myseneca.ca
// Section:        NAA
// Date:           June 4, 2020 
//==============================================
// Workshop:       2
// Part:           2
//==============================================


#ifndef GIFT_H
#define GIFT_H

namespace sdds {
	const int MAX_DESC = 15;
	const float MAX_PRICE = 999.999;
	const int MAX_WRAP = 20;
}

using namespace sdds;

struct Wrapping {
	char* m_pattern; //stores strings of dynamic length to describe pattern of wrapping paper
};

struct Gift {
	char m_description[MAX_DESC]; //description of gift
	double m_price; //$0-MAX_PRICE price range
	int m_units; //minimum 1, number of units/copies of gift
	int m_wrapLayers; //number of layers of wrap
	Wrapping *m_wrap; //dynamically allocated array of size m_pattern;
};

void gifting(char*);
void gifting(double&);
void gifting(int&);
void display(const Gift&);
bool wrap(Gift&);
bool unwrap(Gift&);
void gifting(Gift&);

#endif