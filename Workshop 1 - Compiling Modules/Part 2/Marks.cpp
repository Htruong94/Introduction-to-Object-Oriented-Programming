//==============================================
// Name:           Hung Truong
// Student Number: 147779193
// Email:          htruong19@myseneca.ca
// Section:        NAA
// Date:           May 30, 2020 
//==============================================
// Workshop:       1
// Part:           2
//==============================================

#include <iostream>
#include <iomanip> //use for precision formatting

#include "Marks.h"
#include "Utils.h"

using namespace std;
using namespace num;

void programTitle() { //displays the title of the program
	cout << "Mark Stats Program" << endl << endl;
}

void markstat() { //collection of all functions and display results
	Program program = { {""} };
	int numMarks = 0;
	int i;

	programTitle();

	cout << "Please enter the assessment name: ";
	cin.getline(program.name, sizeof(program.name));

	cout << "Please enter the number of marks: ";
	numMarks = getInt(MIN_NUM_MARKS,MAX_NUM_MARKS);

	cout << "Please enter 9 marks (" << MIN_GRADE << "<=Mark<=" << MAX_GRADE << "):" << endl;
	
	marking(program.marks, numMarks);
	sort(program.marks, numMarks);

	cout << "Thank you..." << endl << "Assessment Name: " << program.name <<endl;
	cout << "----------------" << endl;

	for (i = 0; i < numMarks; i++) {
		cout << program.marks[i];
		program.markSum += program.marks[i];
		if (i != numMarks-1) {
			cout << ", ";
		}
		if (program.marks[i] >= 50) {
			program.pass++;
		}
	}
	
	cout << endl << "Average: " << setprecision(3) << program.markSum / numMarks<< endl;
	cout << "Number of Passing Marks: " << program.pass << endl;
}

void marking(int *mark, int numMarks) { //obtain number of marks equal to numMarks from user
	int i;
	for (i = 0; i < numMarks; i++) {
		cout << i+1 << "> ";
		mark[i] = getInt(MIN_GRADE, MAX_GRADE);
	}
}

