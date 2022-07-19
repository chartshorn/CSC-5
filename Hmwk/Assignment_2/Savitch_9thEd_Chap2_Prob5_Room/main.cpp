/* 
 * File:   main.cpp
 * Author: Caden Hartshorn
 * Created on July 02 2022
 * Purpose: Calculate room occupancy and limits.
 */

//System Libraries
#include <iostream>
#include <cmath>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    unsigned short numPpl, // number of people in the room
            lglPpl; // number of people that can legally be in the room
    short diffPpl; // difference between legal and allowed ppl
    
    //Initialize Variables
    cout << "Input the maximum room capacity and the number of people" << endl;
    cin >> lglPpl >> numPpl;
    
    //Map inputs to outputs -> The Process
    diffPpl = lglPpl - numPpl;
    
    //Display Results
    //if there is room to spare, output success message
    // else output fail message
    if (diffPpl >= 0) {
        cout << "Meeting can be held." << endl;
        cout << "Increase number of people by " << diffPpl << " will be allowed without violation.";
    } else {
        cout << "Meeting cannot be held." << endl;
        cout << "Reduce number of people by " << abs(diffPpl) << " to avoid fire violation.";
    }
    
    //Exit stage right 
    return 0;
}

