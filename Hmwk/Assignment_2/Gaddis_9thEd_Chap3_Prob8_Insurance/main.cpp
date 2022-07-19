/* 
 * File:   main.cpp
 * Author: Caden Hartshorn
 * Created on June 22, 2022, 8:02 PM
 * Purpose: Calculate the minimum advisable insurance amount
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    float advsPrcntg, // advised percentage of the value of a buildings replacement cost to insure
        mnmRplcCst, // minimum replacement cost for the building (user supplied)
        rcIns; // recommended insurance amount
    
    //Initialize Variables
    //constants
    advsPrcntg = 0.8f; // 80 % 
    
    //User Input
    cout << "Insurance Calculator" << endl;
    cout << "How much is your house worth?" << endl;
    cin >> mnmRplcCst;
    
    //Map inputs to outputs -> The Process
    rcIns = advsPrcntg * mnmRplcCst; // recommended insurance = advised percentage * minimum replacement cost
    
    //Display Results
    cout << "You need $" << rcIns << " of insurance.";
    
    //Exit stage right 
    return 0;
}

