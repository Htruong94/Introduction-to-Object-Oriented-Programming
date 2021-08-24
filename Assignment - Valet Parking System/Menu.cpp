/* Citation and Sources...
Final Project Milestone 6
Module: Menu
Filename: Menu.cpp
Version 1.0
Author Hung Truong - 147779193
Revision History
-----------------------------------------------------------
Date Reason
2020/7/9 Prelimary Release
2020/7/11 Re-worked
2020/7/12 Release
2020/7/13 Resolve memory leaks
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/

#include <iostream>
#include "Menu.h"
#include "Utils.h"

using namespace sdds;
using namespace std;

//Menu Functions

Menu::Menu() { //empty state construction
	//cout << endl << "DEFAULT CONSTRUCTOR OF MENU" << endl;
	m_Title = nullptr;
	for (int i = 0; i <= MAX_NO_OF_ITEMS - 1; i++) {
		m_ptrItems[i] = nullptr;
	}
	m_indlvl = 0;
	m_numItem = 0;
}

Menu::Menu(const char* desc, int indlvl) {
	//cout << endl << "CUSTOM CONSTRUCTOR OF MENU" << endl;
	if (desc != nullptr) {
		m_Title = new char[wordLength(desc) + 1];
		for (int i = 0; i <= wordLength(desc); i++) {
			m_Title[i] = desc[i];
		}
		for (int i = 0; i <= MAX_NO_OF_ITEMS - 1; i++) {
			m_ptrItems[i] = nullptr;
		}
		m_indlvl = indlvl;
		m_numItem = 0;
		//cout << endl << m_Title << " length: " << wordLength(desc) << " indlvl: " << m_indlvl << endl;//test statement to see if string copied
	}
}

Menu::operator bool() const {
	return m_Title != nullptr;
}

bool Menu::isEmpty() const {
	if (bool()) {
		return false;
	}
	else {
		return true;
	}
}

void Menu::display() const {

	if (m_Title == nullptr) {
		cout << "Invalid Menu!" << endl;
	}
	else {
		for (int a = 0; a < m_indlvl; a++) {
			cout << "    ";
		}
		cout << m_Title << endl;
		if (m_numItem == 0) {
			cout << "No Items to display!" << endl;
		}
		else {
			for (int i = 0; i < m_numItem; i++) {
				for (int a = 0; a < m_indlvl; a++) {
					cout << "    ";
				}

				cout << i + 1 << "- ";

				m_ptrItems[i]->display();
			}
			for (int a = 0; a < m_indlvl; a++) {
				cout << "    ";
			};
			cout << "> ";
		}
	}
}

Menu& Menu::operator = (const char* desc) {
	delete[] m_Title;
	m_Title = nullptr;

	if (desc != nullptr) {
		m_Title = new char[wordLength(desc) + 1];
		for (int i = 0; i <= wordLength(desc); i++) {
			m_Title[i] = desc[i];
		}
	}
	else {
		for (int i = 0; i < MAX_NO_OF_ITEMS; i++) {
			delete m_ptrItems[i];
			m_ptrItems[i] = nullptr;
		}
		m_numItem = 0;
	}

	return *this;
}

void Menu::add(const char* desc) {
	if (desc != nullptr && m_numItem < MAX_NO_OF_ITEMS && m_Title != nullptr) {
		m_ptrItems[m_numItem] = new MenuItem(desc);
		m_numItem++;
		//cout << m_ptrItems[m_numItem-1]->m_item << " SUCCESS, NUMBER OF ITEMS: " << m_numItem << endl;
	}
	else if (desc == nullptr) {
		delete[] m_Title;
		m_Title = nullptr;
	}
}

Menu& Menu::operator<<(const char* desc) {
	add(desc);

	return *this;
}

int Menu::run() const {
	int igr = 0;
	if (m_Title == nullptr) {
		cout << "Invalid Menu!" << endl;
		return igr;
	}
	else {
		display();
		if (m_numItem != 0) {
			igr = getInt(1, m_numItem);
		}
	}
	return igr;
}

Menu::operator int() const {
	int igr = 0;
	igr = run();

	return igr;
}

Menu& Menu::operator = (const Menu& copy) {
	if (this != &copy) {
		if (copy.m_Title != nullptr) {

			m_indlvl = copy.m_indlvl;
			m_numItem = copy.m_numItem;

			for (int i = 0; i < MAX_NO_OF_ITEMS; i++) {
				delete m_ptrItems[i];
				m_ptrItems[i] = nullptr;
			}

			for (int i = 0; i < m_numItem; i++) {
				m_ptrItems[i] = new MenuItem(copy.m_ptrItems[i]->m_item);
			}

			delete[] m_Title;
			if (copy.m_Title != nullptr) {
				m_Title = new char[wordLength(copy.m_Title) + 1];
				for (int i = 0; i <= wordLength(copy.m_Title); i++) {
					m_Title[i] = copy.m_Title[i];
				}
			}
		}
		else {
			delete[] m_Title;
			m_Title = nullptr;
		}
	}
	return *this;
}

Menu::Menu(const Menu& copy) {

	m_indlvl = copy.m_indlvl;
	m_numItem = copy.m_numItem;

	for (int i = 0; i < m_numItem; i++) {
		m_ptrItems[i] = new MenuItem(copy.m_ptrItems[i]->m_item);
	}

	if (copy.m_Title != nullptr) {
		m_Title = new char[wordLength(copy.m_Title) + 1];
		for (int i = 0; i <= wordLength(copy.m_Title); i++) {
			m_Title[i] = copy.m_Title[i];
		}
	}
}

Menu::~Menu() {
	delete [] m_Title;
	m_Title = nullptr;

	if (m_ptrItems[0] != nullptr) {
		for (int i = 0; i < m_numItem; i++) {
			delete m_ptrItems[i];
			m_ptrItems[i] = nullptr;
		}
	}
	m_numItem = 0;
	m_indlvl = 0;
}

//MenuItem Functions

MenuItem::MenuItem() {
	m_item = nullptr;
}

MenuItem::MenuItem(const char* desc) {
	m_item = nullptr;
	if (desc != nullptr && desc[0] != '\0') {
		m_item = new char[wordLength(desc) + 1];
		for (int i = 0; i <= wordLength(desc); i++) {
			m_item[i] = desc[i];
		}
		//cout << endl << m_item << " length: " << wordLength(desc) << endl;//test statement to see if string copied
	}
}

void MenuItem::display() const {
	if (m_item != nullptr) {
		cout << m_item << endl;
	}
}

MenuItem::~MenuItem() {
	delete[] m_item;
	m_item = nullptr;
}