/* 
 * File:   main.cpp
 * Author: Caden Hartshorn
 * Created on July 12 2022 @ 1436
 * Purpose: generate a rectangle
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
    short size; // size of rectangle
    char symbol; // symbol to make up rectangle
    
    //Initialize or input i.e. set variable values
    cin >> size >> symbol;
    
    //input validation per problem specs
    if (size > 15 || size <= 0) {
        cout << "*** ERROR: Invalid Size ***" << endl;
        return 1;
    }
    
    //Map inputs -> outputs
    for (short i = 0; i < size; i++) {
        // output a row of the desired symbol
        for (short i = 0; i < size; i++) {
            cout << symbol; // output a column of the desire symbol
        }
        if (i != size-1) cout << endl; // do not include endl on last loop per problem specs
    }
    
    //Display the outputs

    //Exit stage right or left!
    return 0;
}