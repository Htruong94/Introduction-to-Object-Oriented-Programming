//==============================================
// Name:           Hung Truong
// Student Number: 147779193
// Email:          htruong19@myseneca.ca
// Section:        NAA
// Date:           June 18, 2020 
//==============================================
// Workshop:       4
// Part:           2
//==============================================

#ifndef GIFT_H
#define GIFT_H
namespace sdds {
	const int MAXNAMELEN = 32;
	const int defaultVal = 0;
	const bool defaultBool = false;
	
	class Saiyan {
		char *m_name; //name of saiyan dynamically allocated according to the input in function call
		int m_dob; //<=2020
		int m_power; // >=0
		bool m_super; //is or is not a super saiyan
		int m_level; //level of super saiyan
	public:
		Saiyan();
		Saiyan(const char* name, int dob, int power, int level = 0, bool super = false);
		void set(const char* name, int dob, int power, int level = 0, bool super = false);
		bool isValid() const;
		void display() const;
		bool fight(Saiyan& other);
		~Saiyan();
	};
}

#endif