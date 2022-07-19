/* 
 * File:   main.cpp
 * Author: Caden Hartshorn
 * Created on June 29, 2022 1213
 * Purpose: Calculate test score averages
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
    float totalScore, // total of all test scores
        avg; // average test score

    //Initialize Variables
    
    //gather user input of test scores
    cout << "Input 5 numbers to average." << endl;

    for (short i = 0; i < 5; i++) {
        short input; // input for loop
        
        cin >> input;
        
        totalScore += input; // increase total score by input
    }
    
    //Map inputs to outputs -> The Process
    avg = totalScore / 5; // determine average by adding all scores and dividing by number of scores
    
    //Display Results
    cout << "The average = ";
    cout << setprecision(1) << fixed << showpoint; // set parameters of output per problem instructions
    cout << avg;
    
    //Exit stage right 
    return 0;
}

