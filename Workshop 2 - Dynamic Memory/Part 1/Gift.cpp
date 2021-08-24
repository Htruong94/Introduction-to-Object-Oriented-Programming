//==============================================
// Name:           Hung Truong
// Student Number: 147779193
// Email:          htruong19@myseneca.ca
// Section:        NAA
// Date:           June 2, 2020 
//==============================================
// Workshop:       2
// Part:           1
//==============================================

#include <iostream>
#include "Gift.h"

using namespace std;
using namespace sdds;

void gifting(char* desc) { //obtains gift description from user input
    cout << "Enter gift description: ";
    cin.width(MAX_DESC + 1);
    cin >> desc;
}
void gifting(double& price) { //obtains gift price from user input when price is in range
    do {
        cout << "Enter gift price: ";
        cin >> price;
        if (price < 0 || price > MAX_PRICE) {
            cout << "Gift price must be between 0 and 999.999" << endl;
        }
    } while (price < 0 || price > MAX_PRICE);
}

void gifting(int& units) { //obtain gift quantity from user input if 1 or above
    do {
        cout << "Enter gift units: ";
        cin >> units;
        if (units <= 0) {
            cout << "Gift units must be at least 1" << endl;
        }
    } while (units <= 0);
}

void display(const Gift& theGift) { //displays the details of gift
    cout << "Gift Details:" << endl;
    cout << " Description: " << theGift.m_description << endl;
    cout << "       Price: " << theGift.m_price << endl;
    cout << "       Units: " << theGift.m_units << endl << endl;
}