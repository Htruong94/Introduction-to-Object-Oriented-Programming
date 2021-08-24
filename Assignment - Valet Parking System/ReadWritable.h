/* Citation and Sources...
Final Project Milestone 6
Module: ReadWritable
Filename: ReadWritable.h
Version 1.0
Author Hung Truong - 147779193
Revision History
-----------------------------------------------------------
Date Reason
July 23, 2020 - Initial Release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/

#ifndef READWRITABLE_H
#define READWRITABLE_H

namespace sdds {
	class ReadWritable {
		bool m_CSVF; //Comma Separated Values flag: bool flag attribute that sees if object is in comma seperated mode or not
	public:
		ReadWritable(); //custom no-argument constructor setting m_CSVF to false
		virtual ~ReadWritable() {}; //empty virtual destructor of ReadWritable Class
		bool isCsv() const; //returns the CSVF;
		void setCsv(bool); //Sets CSVF to the input bool
		virtual std::istream& read(std::istream& istr) = 0; //Read pure virtual function 
		virtual std::ostream& write(std::ostream& ostr) const = 0; //Write pure virtual function 
	};

	std::ostream& operator << (std::ostream& os, const ReadWritable& src); //helper function to read function
	std::istream& operator >> (std::istream& in, ReadWritable& src); //helper function to write function
}

#endif