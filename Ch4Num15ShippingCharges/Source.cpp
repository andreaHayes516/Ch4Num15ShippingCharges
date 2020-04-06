/************************************************
** Author: Andrea Hayes
** Date: March 7, 2020
** Purpose: Calculate shipping charges based on distance 
            and weight.
** Input: Weight and distance
** Processing: Calcuate shipping cost, input valitation for weight and distance.
** Output: Display the cost of charges.
*************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

const double TWO_KG_OR_LESS = 1.10; // Current shipping charges based on weight. 
const double TWO_TO_SIX = 2.20;
const double SIX_TO_TEN = 3.70;
const double TEN_TO_TWENTY = 4.80;

int main() {

    double weight, distance, rate, shipCost;
    
    cout << "Enter package weight in kilograms: ";
    cin >> weight;

    if (weight < 0 || weight > 20) { // Only allows packages weiging between 0 and 20 kg
        cout << "Invalid wieght. We only ship packages between 0 and 20 KG." << endl;
        return 1;
    }

    cout << "Enter distance to be shipped in miles(do not include commas): ";
    cin >> distance;

    if (distance < 10 || distance > 3000) { // Only allows distane of 10 to 3,000 miles
        cout << "Invaild distance. We only ship packages between 10 - 3,000 miles." << endl;
        return 1;
    }

    if (weight <= 2) { // For packages less than 2 kg
        rate = TWO_KG_OR_LESS;
    }
    else if (weight <= 6) { // For packages more than 2 and up to 6 kg
        rate = TWO_TO_SIX;
    }
    else if (weight <= 10) { // For packages more than 6 and up to 10 kg
        rate = SIX_TO_TEN;
    }
    else if (weight <= 20) { // For packages more than 10 and up to 20 kg
        rate = TEN_TO_TWENTY;
    }
    shipCost = rate * distance / 500; // Calculates cost to ship. Rate is per 500 miles. 
   
    cout << fixed << setprecision(2) << showpoint;
    cout << "The cost to ship this package is $" << shipCost << endl;

    return 0;
}