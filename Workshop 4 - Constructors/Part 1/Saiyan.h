//==============================================
// Name:           Hung Truong
// Student Number: 147779193
// Email:          htruong19@myseneca.ca
// Section:        NAA
// Date:           June 16, 2020 
//==============================================
// Workshop:       4
// Part:           1
//==============================================

#ifndef GIFT_H
#define GIFT_H
namespace sdds {
	const int MAXNAMELEN = 32;
	const int defaultVal = 0;
	const char defaultChar = '\0';
	const bool defaultBool = false;
	
	class Saiyan {
		char m_name[MAXNAMELEN]; 
		int m_dob; //<=2020
		int m_power; // >=0
		bool m_super; 
	public:
		Saiyan();
		Saiyan(const char* name, int dob, int power);
		void set(const char* name, int dob, int power, bool super = false);
		bool isValid() const;
		void display() const;
		bool fight(const Saiyan& other) const;
	};
}

#endif