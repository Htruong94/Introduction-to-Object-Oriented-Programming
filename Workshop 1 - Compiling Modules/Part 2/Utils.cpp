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
#include <iomanip>	

#include "Utils.h"
#include "Marks.h"

using namespace std;
using namespace num;

int getInt(int min, int max) { //obtains a min and max value when called and takes input of user until a valid input is obtained
	int igr = 0;
	char bfr;
	
	bool integer = false;
	while (!integer) {
		if (cin >> igr) { //if integer is input first
			if (cin.get(bfr)) { //obtains buffer input
				cin.putback(bfr); //place bfr back into buffer 
				if (bfr == '\n') {  //if the input after the integer is enter
					if (igr < min || igr > max) {
						cout << "Invalid value (" << min << "<=value<=" << max << "), try again: ";
					}
					else {
						integer = true;
					}
				}
				else { //if the input after the integer is not enter
					cout << "Invalid trailing characters, try again: ";
				}
			}
			cin.clear(); //clears buffers
		}
		else { //if integer is not obtained from input
			cout << "Invalid Number, try again: ";
			cin.clear();
		}
		cin.ignore(100, '\n'); //ignore and discard 100 chacters before the \n
	}

	return igr;
}

void sort(int* mark, int numMarks) { //sorts an array from high to low
	int a, b, max, temp;
	for (a = 0;a < numMarks; a++) {
		max = a;
		for (b = a + 1; b < numMarks; b++) {
			if (mark[b] > mark[max]) {
				max = b;
			}
		}
		temp = mark[a];
		mark[a] = mark[max];
		mark[max] = temp;
	}
}
