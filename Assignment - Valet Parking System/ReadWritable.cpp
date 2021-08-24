/* Citation and Sources...
Final Project Milestone 6
Module: ReadWritable
Filename: ReadWritable.cpp
Version 1.0
Author Hung Truong - 147779193
Revision History
-----------------------------------------------------------
Date Reason
July 17, 2020 - Initial Release
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
#include "ReadWritable.h"

using namespace sdds;

ReadWritable::ReadWritable() {
	m_CSVF = false;
}

bool ReadWritable::isCsv() const {
	if (m_CSVF == false) {//returns CSVF boolean
		return false;
	}
	else {
		return true;
	}
}

void ReadWritable::setCsv(bool csvf) {
	m_CSVF = csvf;
}

std::ostream& sdds::operator << (std::ostream& ostr, const ReadWritable& src) {
	src.write(ostr); //takes the class and call the write function of the class
	return ostr;
}

std::istream& sdds::operator >> (std::istream& istr, ReadWritable& src) {
	src.read(istr); //takes the class and call the read function of the class
	return istr;
}