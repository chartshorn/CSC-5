/* 
 * File:   main.cpp
 * Author: Caden Hartshorn
 * Created on June 22, 2022, 1836
 * Purpose: Calculate ocean rise over time
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
//Function to calculate ocean rise based on year
float calcRise(float, short);

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    float rsRt, //how much ocean rises each year
        ocnRs5, //how much the ocean will rise in 5 years
        ocnRs7, //how much the ocean will rise in 7 years
        ocnRs10; //how much the ocean will rise in 10 years
    
    //Initialize Variables
    rsRt = 1.5f; // 1.5 millimeters / year
    
    //Map inputs to outputs -> The Process
    ocnRs5 = calcRise(rsRt, 5); // Rise for 5 years
    ocnRs7 = calcRise(rsRt, 7); // Rise for 7 years
    ocnRs10 = calcRise(rsRt, 10); // Rise for 10 years
    
    //Display Results
    //Results displayed when function called
    
    //Exit stage right 
    return 0;
}

float calcRise(float rt, short yrs) {
    //declare variables
    float rsAmnt; // how much the ocean will rise over the specified time fraewe
    //init variables
    rsAmnt = rt*yrs; // ocean rise amount = rise rate * years
    //map inputs to outputs -> the process
    cout<<"In "<<yrs<<" Years The Ocean Will Rise "<<rsAmnt<<" Millimeters"<<endl;
    return rsAmnt;
}