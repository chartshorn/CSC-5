/* 
 * File:   main.cpp
 * Author: Caden Hartshorn
 * Created on July 12 2022 @ 1400
 * Purpose: Generate a pattern given an input
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
    short inpt; // input var
    
    //Initialize or input i.e. set variable values
    cin >> inpt;
    
    //Map inputs -> outputs
    // loop through every number below one, generate row
    for (short i = 1; i < inpt+1; i++) {
        //loop through row, generate columns
        for (short w = 1; w < i+1; w++) {
            cout << "+";
        }
        
        // generate endls
        cout << endl;
        cout << endl;
    }
    
    //starting at the max, loop through every number until zero, generate row
    for (short i = inpt; i > 0; i--) {
        //loop through row, generate columns
        for (short w = 1; w < i+1; w++) {
            cout << "+";
        }
        
        //format new line per problem specs
        if (i != 1) {
            cout << endl;
            cout << endl;
        }
    }
    
    //Display the outputs

    //Exit stage right or left!
    return 0;
}