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
#include "Gift.h" // Intentional
using namespace std;
using namespace sdds;

int main() {
    int numberOfGifts = 0; // Initial number of Gifts
    // TODO 1: declare a pointer for a dynamic array of Gifts (remember to initialize it)
   
    Gift* pGifts = nullptr;

    // END TODO 1

    cout << "Enter number of Gifts to allocate: ";
    cin >> numberOfGifts;

    if (numberOfGifts < 1)
        return 1;

    // TODO 2: allocate dynamic memory for the gifts pointer using the numberOfGifts
    pGifts = new Gift[numberOfGifts];
    // END TODO 2

    for (int i = 0; i < numberOfGifts; ++i)
    {
        cout << "Gift #" << i + 1 << ": " << endl;
        
        // TODO 3: utilizing the gifting functions, allow input for the gift's description
        gifting(pGifts[i].m_description);
        // END TODO 3
        
        cin.ignore(2000, '\n'); // clear input buffer
        
        // TODO 4: utilizing the gifting functions, allow the user to input the gift's price
        gifting(pGifts[i].m_price);
        // END TODO 4
        
        cin.ignore(2000, '\n'); // clear input buffer
        
        // TODO 5: utilizing the gifting functions, allow the user to input the units of gift
        gifting(pGifts[i].m_units);
        // END TODO 5
        cin.ignore(2000, '\n');
        cout << endl;
    }


    // TODO 6: display the details of each gift using the Gifts module display function
    for (int i = 0; i < numberOfGifts; i++) {
        cout << "Gift #" << i + 1 << ": " <<endl;
        display(pGifts[i]);
    }

    // END TODO 6



    // TODO 7: deallocate the gifts pointer here to avoid memory as we are done with it
    delete[] pGifts;
    pGifts = nullptr;
    // END TODO 7

    return 0;
}