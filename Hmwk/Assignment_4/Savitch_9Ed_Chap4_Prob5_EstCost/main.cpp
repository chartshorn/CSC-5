/* 
 * File: main.cpp
 * Author:  Caden Hartshorn
 * Created on July 12 2022 @ 1552
 * Purpose:  Calculate inflation rate and future prices
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
//Purpose: Calculate inflation rate
//Input: (Float curPrc - Current price in USD) (Float oldPrc - Price from one year ago in usd)
//Returns: float rate - percentage rate of inflation
float calcInf ( float, float );

//Execution Begins Here!
int main(int argc, char** argv) {
    //loop Variables
    bool wntLoop;
    wntLoop = true;
    
    while (wntLoop) {
        //Declare Variables
        float oldPrc, // old price
        curPrc, // current price
        yr1Prc, // price in 1 year
        yr2Prc, // price in 2 years
        infRate; // inflation rate
        char yesNo; // user input - y/n continue the loop
        
        //Initialize or input i.e. set variable values
        cout << "Enter current price:" << endl;
        cin >> curPrc;
        cout << "Enter year-ago price:" << endl;
        cin >> oldPrc;
        
        //Map inputs -> outputs
        infRate = calcInf(curPrc, oldPrc); // calculate inflation rate
        yr1Prc = curPrc + curPrc * infRate * .01; // calculate the price one year from now assuming current price and constant inflation rate
        yr2Prc = yr1Prc + yr1Prc * infRate * .01; // calculate the price two years from now assuming yr1 price and constant inflation rate
        
        //Display the outputs
        cout << "Inflation rate: " << setprecision(2) << fixed << infRate << "%" << endl << endl;
        cout << "Price in one year: $" << yr1Prc << endl;
        cout << "Price in two year: $" << yr2Prc << endl << endl;
        
        cout << "Again:" << endl;
        cin >> yesNo;
        
        //determine whether user wants to run the scenario again
        if (yesNo == 'y') {
             cout << endl;
        } else {
            wntLoop = false;
        }
    }
    

    //Exit stage right or left!
    return 0;
}

float calcInf(float curPrc, float oldPrc) {
    return (( curPrc / oldPrc ) - 1.0f) * 100; //inflation rate is equal to current price / old price - 1, converted to percentage
}