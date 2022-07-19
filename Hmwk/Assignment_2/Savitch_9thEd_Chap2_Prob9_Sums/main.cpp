/* 
 * File:   main.cpp
 * Author: Caden Hartshorn
 * Created on July 02, 2022, 2043
 * Purpose: Sum positive, negative and all numbers
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    short inpt,
        pSum,
        nSum,
        sum;
    
    //Initialize Variables
    //base vals
    pSum = 0;
    nSum = 0;
    sum = 0;
  
    cout << "Input 10 numbers, any order, positive or negative" << endl;
    
    //Map inputs to outputs -> The Process
    // ask the user for input 10 times
    for (int i = 0; i < 10; i++) {
        cin >> inpt;
        
        if (inpt > 0) {
            pSum += inpt;
        } else {
            nSum += inpt;
        }
        sum += inpt;
    }
    
    //Display Results
    cout << "Negative sum = " << setw(3) << nSum << endl;
    cout << "Positive sum = " << setw(3) << pSum << endl;
    cout << "Total sum    = " << setw(3) << sum;
    
    //Exit stage right 
    return 0;
}

