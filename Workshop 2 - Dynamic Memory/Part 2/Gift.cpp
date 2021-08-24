//==============================================
// Name:           Hung Truong
// Student Number: 147779193
// Email:          htruong19@myseneca.ca
// Section:        NAA
// Date:           June 4, 2020 
//==============================================
// Workshop:       2
// Part:           2
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
    cout << "       Units: " << theGift.m_units << endl;

    if (theGift.m_wrap == nullptr) {
        cout << "Unwrapped!" << endl;
    }
    else {
        cout << "Wrap Layers: " << theGift.m_wrapLayers << endl;
        for (int i = 0; i < theGift.m_wrapLayers; i++) {
            cout << "Wrap #" << i + 1 << " -> " << theGift.m_wrap[i].m_pattern << endl;
        }
    }
}

bool wrap(Gift& theGift) { //Wraps an unwrapped gift
    char bfr[256] = { '\0' };
    int a;

    if (theGift.m_wrap == nullptr) { //nullptr represents an unwrap gift
        cout << "Wrapping gifts..." << endl;
        do {
            cout << "Enter the number of wrapping layers for the Gift: ";
            cin >> theGift.m_wrapLayers;
            cin.ignore(2000, '\n');
            cin.clear();

            if (theGift.m_wrapLayers < 1) {
                cout << "Layers at minimum must be 1, try again." << endl;
            }
            else if(theGift.m_wrapLayers >= MAX_WRAP) {
                cout << "Layers maximum is " << MAX_WRAP << ", try again." << endl;
            }
            else {
                theGift.m_wrap = new Wrapping[theGift.m_wrapLayers];
                
                for (int i = 0; i < theGift.m_wrapLayers; i++) {
                    cout << "Enter wrapping pattern #" << i + 1 << ": ";
                    cin >> bfr;

                    for (a = 0; bfr[a] != '\0'; a++){
                    }

                    theGift.m_wrap[i].m_pattern = new char[a+1];
                    
                    for (int b = 0; b <= a; b++) {
                        theGift.m_wrap[i].m_pattern[b] = bfr[b];
                    }

                    bfr[0] = '\0'; //sets bfr to \0

                    cin.ignore(2000, '\n');
                    cin.clear();
                }
                
            }
        } while (theGift.m_wrap == nullptr);
        return true;
    }
    else {
        cout << "Gift is already wrapped!" << endl;
        return false;
    }
}

bool unwrap(Gift& theGift) { //unwraps a wrapped gift
    if (theGift.m_wrap == nullptr) {
        cout << "Gift isn't wrapped! Cannot unwrap." << endl;
        return false;
    }
    else {
        cout << "Gift being unwrapped." << endl;

        for (int i = 0; i < theGift.m_wrapLayers; i++) {
            delete [] theGift.m_wrap[i].m_pattern;
            theGift.m_wrap[i].m_pattern = nullptr;
        }

        delete [] theGift.m_wrap; //deallocate m_wrap
        theGift.m_wrap = nullptr;

        return true;
    }
}

void gifting(Gift& theGift) { //calls other wrap function
    cout << "Preparing a gift..." << endl;
   
    gifting(theGift.m_description);
    gifting(theGift.m_price);
    gifting(theGift.m_units);

    wrap(theGift);
}