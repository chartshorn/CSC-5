/* 
 * File:   main.cpp
 * Author: Caden Hartshorn
 * Created on June 22, 2022, 8:02 PM
 * Purpose: C++ Template - To be used in all future assignments
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
    unsigned short Op1, //arbitrary values picked by textbook 
        Op2, // ^         
        Op3, // ^
        Op4, // ^
        Op5, // ^
        sm, // sum of all values
        avg; // average of all values
    
    //Initialize Variables
    Op1 = 28; //arbitrary values picked by textbook 
    Op2 = 32; // ^
    Op3 = 37; // ^
    Op4 = 24; // ^
    Op5 = 33; // ^
    
    //Map inputs to outputs -> The Process
    //Add all operators together and store the result in sum variable
    sm = Op1 + Op2 + Op3 + Op4 + Op5;
    
    //Divide sum by number of operators to ascertain average
    avg = sm/5;
    
    //Display Results
    cout<<"The average of the operators is: "<<avg<<endl;
   
    //Exit stage right 
    return 0;
}

