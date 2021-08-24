/* Citation and Sources...
Final Project Milestone 6
Module: Menu
Filename: Menu.h
Version 1.0
Author Hung Truong
Revision History
-----------------------------------------------------------
Date Reason
2020/7/9 Preliminary release
2020/7/12 Updated class function declarations
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/
#ifndef MENU_H
#define MENU_H

namespace sdds {
	const int MAX_NO_OF_ITEMS = 10;
	class Menu; //forward declaration of Menu class

	class MenuItem {
		char* m_item; // holds the name of the item of unknown size
		MenuItem(); //default constructor of MenuItem
		MenuItem(const char*); //constructor of MenuItem
		void display() const; //Displays itself its content
		MenuItem(const MenuItem&) = delete; //Copy prohibited function that enforces that you cannot copy the content inside the class
		~MenuItem(); //destructor of MenuItem
		friend class Menu; //declare friendship with class menu
	};

	class Menu {
		char* m_Title; // title of the menu of an unknown size
		MenuItem* m_ptrItems[MAX_NO_OF_ITEMS]; // points to an array of MenuItems
		int m_indlvl; //indicates how much indentation is used [4*indentationLevel spaces]
		int m_numItem; //indicates how much items are presently in the menu
	public:
		Menu(); //Defualt Constructor of Menu
		Menu(const char*, int = 0); //Custom Constructor of Menu
		operator bool() const; //Checks if menu is valid and usable (returns true if valid and usable)
		bool isEmpty() const; //Checks if menu is empty, returns true if empty
		void display() const; //displays the content of the menu
		Menu& operator = (const char*); //allows to reset the title of the menu
		void add(const char*); //points MenuItem to array of MenuItem if there is space in the array 
		Menu& operator<<(const char* desc); //inserts C-strings into the Menu as MenuItems similar to add function
		int run() const; //displays menu and allow for interaction with user's reaponse
		operator int() const; //insert cast overload that calls the run function
		Menu& operator = (const Menu&); //copy assignment from menu class to menu class
		Menu(const Menu&); // copy constructor of the menu class
		~Menu(); //destructor of Menu
	};
}

#endif