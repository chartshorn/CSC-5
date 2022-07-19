/* 
 * File:   main.cpp
 * Author: Caden Hartshorn
 * Created on June 29, 2022, 2120
 * Purpose: Convert Fahrenheit to celsius
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    float clsTmp, // temperature in celsius
        frnTmp; // temperature in Fahrenheit
    
    //Initialize Variables
    cout << "Temperature Converter" << endl;
    cout << "Input Degrees Fahrenheit" << endl;
    cin >> frnTmp;
    
    //Map inputs to outputs -> The Process
    clsTmp = 5.0f/9.0f * (frnTmp - 32); // celsius temperature = 5/9(fahrenheit temp - 32)
    
    //Display Results
    cout << setprecision(1) << fixed << showpoint;
    cout << frnTmp << " Degrees Fahrenheit = " << clsTmp << " Degrees Centigrade";
    
    //Exit stage right 
    return 0;
}

