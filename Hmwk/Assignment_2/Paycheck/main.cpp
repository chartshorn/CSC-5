/* 
 * File:   main.cpp
 * Author: Caden Hartshorn
 * Created on July 02, 2022, 1915
 * Purpose: Calculate gross pay of a worker
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
    float grsPy; // gross pay
    unsigned short pyRt, // hourly pay rate
        numHrs; // number of hours worked
    
    //Initialize Variables
    cout << "This program calculates the gross paycheck." << endl;
    cout << "Input the pay rate in $'s/hr and the number of hours." << endl;
    cin >> pyRt >> numHrs;
    
    //Map inputs to outputs -> The Process
    grsPy = pyRt * numHrs; // pay = pay rate * number of hours
    grsPy += numHrs > 40? pyRt * (numHrs-40):0; // if num hours exceeds forty, calc double time 
    
    //Display Results
    cout << "Paycheck = $";
    cout << fixed << showpoint << setprecision(2) << setw(7); //money formatting
    cout << grsPy;
    
    //Exit stage right 
    return 0;
}

