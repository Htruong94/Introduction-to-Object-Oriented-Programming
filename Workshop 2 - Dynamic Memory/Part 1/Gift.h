//==============================================
// Name:           Hung Truong
// Student Number: 147779193
// Email:          htruong19@myseneca.ca
// Section:        NAA
// Date:           June 2, 2020 
//==============================================
// Workshop:       2
// Part:           1
//==============================================

#ifndef GIFT_H
#define GIFT_H

namespace sdds {
	const int MAX_DESC = 15;
	const int MAX_PRICE = 999.999;
}

using namespace sdds;

struct Gift {
	char m_description[MAX_DESC]; //description of gift
	double m_price; //$0-MAX_PRICE price range
	int m_units; //minimum 1, number of units/copies of gift
};

void gifting(char* desc);
void gifting(double& price);
void gifting(int& units);
void display(const Gift& theGift);

#endif