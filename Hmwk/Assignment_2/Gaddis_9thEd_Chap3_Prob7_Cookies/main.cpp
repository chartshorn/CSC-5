/* 
 * File:   main.cpp
 * Author: Caden Hartshorn
 * Created on June 29, 2022, 2109
 * Purpose: Calculate calories based on consumption
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
    unsigned short etnCks, // how many cookies the user ate
        clsPrCk, // calories per cookie
        ttlCls; // total calories
            
    //Initialize Variables
    //constants
    clsPrCk = 75; // 75 cals / cookie
    
    //gather user input
    cout << "Calorie Counter" << endl;
    cout << "How many cookies did you eat?" << endl;
    cin >> etnCks;
    
    //Map inputs to outputs -> The Process
    ttlCls = clsPrCk * etnCks; // total calories = calories per cookie * eaten calories
    
    //Display Results
    cout << "You consumed " << ttlCls << " calories.";
    
    //Exit stage right 
    return 0;
}

