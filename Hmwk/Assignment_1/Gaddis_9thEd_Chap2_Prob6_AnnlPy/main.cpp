/* 
 * File:   main.cpp
 * Author: Caden Hartshorn
 * Created on June 23, 2022, 1830
 * Purpose: calculate an employees total annual pay
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
    //Integer used as short is too small
    int pyAmnt, //employee pay per period
        pyPrds, //number of pay periods / yr
        anlPy; //employee salary
    
    //Initialize Variables
    pyAmnt = 2200; //$2200 usd per pay period
    pyPrds = 26; //biweekly pay period
    
    //Map inputs to outputs -> The Process
    anlPy = pyAmnt * pyPrds; //employee salary calculated by pay per period * pay periods / yr
    
    //Display Results
    cout<<"Employee Annual Pay is: $"<<anlPy<<endl;
    
    //Exit stage right 
    return 0;
}

