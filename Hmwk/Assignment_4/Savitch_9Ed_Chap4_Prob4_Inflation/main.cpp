/* 
 * File: main.cpp
 * Author:  Caden Hartshorn
 * Created on July 12 2022 @ 1552
 * Purpose:  Calculate inflation rate
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //loop Variables
    bool wntLoop;
    wntLoop = true;
    
    while (wntLoop) {
        //Declare Variables
        float oldPrc, // old price
        curPrc, // current price
        infRate; // inflation rate
        char yesNo; // user input - y/n continue the loop
        
        //Initialize or input i.e. set variable values
        cout << "Enter current price:" << endl;
        cin >> curPrc;
        cout << "Enter year-ago price:" << endl;
        cin >> oldPrc;
        
        //Map inputs -> outputs
        //inflation rate is equal to current price / old price - 1, converted to percentage
        infRate = (( curPrc / oldPrc ) - 1.0f) * 100;
        
        //Display the outputs
        cout << "Inflation rate: " << setprecision(2) << fixed << infRate << "%" << endl << endl;
        
        cout << "Again:" << endl;
        cin >> yesNo;
        
        if (yesNo == 'y') {
             cout << endl;
        } else {
            wntLoop = false;
        }
    }
    

    //Exit stage right or left!
    return 0;
}