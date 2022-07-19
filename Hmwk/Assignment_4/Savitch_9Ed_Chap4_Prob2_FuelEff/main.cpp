/* 
 * File: main.cpp
 * Author: Caden Hartshorn
 * Created on July 12 2022 @ 1447
 * Purpose: calculate mpg of a car
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
const float lToG = .264179; // factor to multiply liters by for gallons

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    // loop controlling variable
    bool cnt = true;
    
    while (cnt) {
        //Declare Variables
        short ltrsCsm, // liters consumed 
        mlsTrvl; // miles travelled
        float glns, // gallons consumd
        mpg; // avg mpg
        char yesNo; //usr input for yes no
        
        
        //Initialize or input i.e. set variable values
        cout << "Enter number of liters of gasoline:" << endl;
        cin >> ltrsCsm;
        cout << endl;
        cout << "Enter number of miles traveled:" << endl;
        cin >> mlsTrvl;
        cout << endl;
        
        //Map inputs -> outputs
        glns = ltrsCsm * lToG; // gallons = liters * liters to gallons factor
        mpg = mlsTrvl / glns; // mpg = miles travelled / gallons
        
        //Display the outputs
        cout << "miles per gallon:" << endl;
        cout << setprecision(2) << fixed << mpg;
        cout << endl;
        
        cout << "Again:" << endl;
        cin >> yesNo;
        
        //restart loop dependent on user input
        if (yesNo == 'y') {
            cout << endl;
        } else {
            cnt = false;
        }
    }
    
    //Exit stage right or left!
    return 0;
}