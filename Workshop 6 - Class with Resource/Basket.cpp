//==============================================
// Name:           Hung Truong
// Student Number: 147779193
// Email:          htruong19@myseneca.ca
// Section:        NAA
// Date:           July 7, 2020
//==============================================
// Workshop:       6
//==============================================

#include <iostream>
#include <iomanip>
#include "Basket.h"

using namespace sdds;
using namespace std;

Basket::Basket() { //default constructor of class Basket
	m_fruits = nullptr;
	m_cnt = 0;
	m_price = 0;
}

Basket::Basket(Fruit* fruit, int count, double price) { //custom constructor of class Basket
	m_fruits = nullptr;
	m_cnt = 0;
	m_price = 0;

	if (count > 0 && price > 0 && fruit != nullptr) {
		m_cnt = count;
		m_price = price;

		m_fruits = new Fruit[m_cnt];
		for (int i = 0; i < m_cnt; i++) {
			m_fruits[i] = fruit[i];
		}
	}
}

Basket::Basket(const Basket& basket) { //Copy constructor of class Basket that performs a deep copy of the object
	m_fruits = nullptr;
	m_cnt = 0;
	m_price = 0;
	
	m_cnt = basket.m_cnt;
	m_price = basket.m_price;
	if (basket.m_fruits != nullptr) {
		m_fruits = new Fruit[m_cnt];
		for (int i = 0; i < m_cnt; i++) {
			m_fruits[i] = basket.m_fruits[i];
		}
	}
}

Basket& Basket::operator = (const Basket& basket) { //Copy assignment that performs a shallow copy of an object of class Baskset

	if (this != &basket) {
		m_cnt = basket.m_cnt;
		m_price = basket.m_price;
		if (basket.m_fruits != nullptr) {
			m_fruits = new Fruit[m_cnt];
			for (int i = 0; i < m_cnt; i++) {
				m_fruits[i] = basket.m_fruits[i];
			}
		}
	}

	return *this;
}

Basket::~Basket() { //Destructor of class Baset
	delete[] m_fruits;
	m_fruits = nullptr;
}

void Basket::setPrice(double price) { //Takes given price and assign to object m_price if price is valid
	if (price > 0) {
		m_price = price;
	}
}

Basket::operator bool() { //Checks if the object is empty which returns a false, true if not empty
	if (m_fruits == nullptr) {
		return false;
	}
	else {
		return true;
	}
}

Basket& Basket::operator+=(Fruit fruit) { //takes given fruit struct and append the fruit to the basket object's fruit array
	Fruit* temp; //temporary object that stores the current basket object

	m_cnt++; //increase amount of fruits in basket

	temp = nullptr;
	temp = new Fruit[m_cnt];

	for (int i = 0; i < m_cnt - 1; i++) { //performs a copy of the fruits
		temp[i] = m_fruits[i];
	}

	delete[] m_fruits; //deallocation of object's m_fruit
	m_fruits = nullptr;
	m_fruits = new Fruit[m_cnt]; //dynamically allocate the new size of m_cnt to the fruit array

	for (int i = 0; i < m_cnt - 1; i++) { //return copy to object
		m_fruits[i] = temp[i];
	}
	
	m_fruits[m_cnt - 1] = fruit; //append the new fruit into the increased size array
	delete[] temp; //deallocation of temp
	temp = nullptr;

	return *this;
}

void Basket::display(std::ostream& os) const{ //display function to show the summary of the items in the object
	if (m_cnt == 0) {
		cout << "The basket is empty!" << endl;
	}
	else {
		cout.setf(ios::fixed);
		cout << "Basket Content:" << endl;
		for (int i = 0; i < m_cnt; i++) {
			cout.width(10);
			cout.precision(2);
			cout << std::right << m_fruits[i].m_name << ": " << m_fruits[i].m_qty << "kg" << endl;
		}
		cout << "Price: " << m_price << endl;
		cout.unsetf(ios::fixed);
		cout.precision(6);
	}
}

std::ostream& sdds::operator<<(std::ostream& os, const Basket& basket) { //helper function that brings the output to the public member of display
	basket.display(os);
	return os;
}