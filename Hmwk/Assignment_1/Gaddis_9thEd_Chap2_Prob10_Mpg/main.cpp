/* 
 * File:   main.cpp
 * Author: Caden Hartshorn
 * Created on June 22, 2022, 2005
 * Purpose: Calculate mpg of a car
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
    short tnkSz, //Gas Tank Size in Gallons
        mlsTlMpty, //How many miles the car can drive in a tank
        mpg; //how many miles per gallon the car gets
    
    //Initialize Variables
    tnkSz = 15; //15 gallons
    mlsTlMpty = 375; //375 miles until empty
    
    //Map inputs to outputs -> The Process
    mpg = mlsTlMpty / tnkSz; //calc mpg by dividing range of miles by gas tank size
    
    //Display Results
    cout<<"Your car's MPG is: "<<mpg<<endl;
    
    //Exit stage right 
    return 0;
}

