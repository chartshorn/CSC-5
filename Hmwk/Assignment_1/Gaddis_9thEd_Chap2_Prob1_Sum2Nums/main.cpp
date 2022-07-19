/* 
 * File:   main.cpp
 * Author: Caden Hartshorn
 * Created on June 22, 2022, 8:02 PM
 * Purpose: To determine the sum of two stored integers
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
    unsigned short Op1, //operator 1
            Op2, //operator 2 
            ttl; //sum of op 1 and 2
    
    //Initialize Variables
    Op1 = 50; //arbitrary values chosen by textbook
    Op2 = 100; //^
    
    //Map inputs to outputs -> The Process
    ttl = Op1 + Op2; //Adds the two operators and assigns to appropriate var
    
    //Display Results
    cout
        <<"The total is: "
        <<ttl    
    <<endl;
    
    //Exit stage right 
    return 0;
}

