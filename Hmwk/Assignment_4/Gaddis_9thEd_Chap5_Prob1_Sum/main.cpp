/* 
 * File:   main.cpp
 * Author: Caden Hartshorn
 * Created on July 11 2022 @ 2106
 * Purpose: Calculate the sum of all numbers
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    short input, // usr input
    total; // sum
    
    //Initialize or input i.e. set variable values
    total = 0; // baseline for total
    cin >> input; // gather input
    
    //Map inputs -> outputs
    //loop starting at zero to input number, add every number in the process.
    for (short i = 1; i < input+1; i++) {
        total += i;
    }
    
    //Display the outputs
    cout << "Sum = " << total;

    //Exit stage right or left!
    return 0;
}