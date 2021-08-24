//==============================================
// Name:           Hung Truong
// Student Number: 147779193
// Email:          htruong19@myseneca.ca
// Section:        NAA
// Date:           June 27, 2020
//==============================================
// Workshop:       5
// Part:           2
//==============================================

#ifndef ENGINE_H
#define ENGINE_H

namespace sdds {
	const int TYPE_MAX_SIZE = 30;
	
	class Engine {
		double m_size; //size of engine
		char m_type[TYPE_MAX_SIZE]; //engine model type of length TYPE_MAX_SIZE
	public:
		Engine();
		Engine(const char* type, double size);
		double get() const;
		void display() const;
	};
	
}

#endif