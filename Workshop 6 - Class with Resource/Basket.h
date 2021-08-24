//==============================================
// Name:           Hung Truong
// Student Number: 147779193
// Email:          htruong19@myseneca.ca
// Section:        NAA
// Date:           July 7, 2020
//==============================================
// Workshop:       6
//==============================================

#ifndef BASKET_H
#define BASKET_H

#include <iostream>

namespace sdds {
	struct Fruit
	{
		char m_name[30 + 1]; // the name of the fruit
		double m_qty;        // quantity in kilograms
	};

	class Basket {
		Fruit* m_fruits;     //dynamically size array that stores a fruit in each element
		int m_cnt;           //The number of fruits in the basket
		double m_price;      //the price of the basket
	public:
		Basket();
		Basket(Fruit*, int, double);
		Basket(const Basket&);
		Basket& operator = (const Basket&);
		~Basket();
		void setPrice(double);
		operator bool();
		Basket& operator+=(Fruit);
		void display(std::ostream& os) const;
	};

	std::ostream &operator<<(std::ostream& os, const Basket& basket);
}

#endif