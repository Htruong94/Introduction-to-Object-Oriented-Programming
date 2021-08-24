//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
//==============================================
// Name:           Hung Truong
// Student Number: 147779193
// Email:          htruong19@myseneca.ca
// Section:        NAA
// Date:           July 28, 2020 
//==============================================
// Workshop:       9
//==============================================

#ifndef VALIDATE_H
#define VALIDATE_H

namespace sict {
	template <typename T> //template for 1st and 2nd parameter of validate
	bool validate(const T& val1, const T* Arr, const int numElem, bool* boolArr) { //3rd and 4rth parameters typing are constant
		bool valid = true; //initialize valid as true
		for (int i = 0; i < numElem; i++) {
			if (Arr[i] >= val1) { //if the value of the array element is greater or equal than the value of the minimum, set the bool array of that element to true, else false
				boolArr[i] = true;
			}
			else { //if a false occurs, set valid to false to signify that there is an element that is false so the function can return false
				boolArr[i] = false;
				valid = false;
			}
		}
		return valid;
	}
}

#endif