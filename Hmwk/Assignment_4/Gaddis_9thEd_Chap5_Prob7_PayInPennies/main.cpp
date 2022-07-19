/* 
 * File:   main.cpp
 * Author: Caden Hartshorn
 * Created on July 11 2022 @ 2110
 * Purpose:  Determine salary in pennies
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>
#include <cmath>
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    short days; // number of days employee worked
    double pay; // pay based on days, must be double due to exponential nature
    
    //Initialize or input i.e. set variable values
    pay = 0; // init pay
    cin >> days;
    
    //input validation
    if (days < 1) {
        cout << "*** ERROR: INVALID DAYS ***";
        return 1;
    }
    
    //Map inputs -> outputs
    //loop through days, calculate pay per problem specs
    for (short i = 1; i < days+1; i++) {
        pay += i == 1 ? .01 : pow(2,i-1) * .01;
    }
    
    
    
    //Display the outputs
    cout << "Pay = $" << setprecision(2) << fixed << pay;

    //Exit stage right or left!
    return 0;
}