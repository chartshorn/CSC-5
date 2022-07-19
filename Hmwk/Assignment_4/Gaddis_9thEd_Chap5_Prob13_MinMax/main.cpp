/* 
 * File:   main.cpp
 * Author: Caden Hartshorn
 * Created on July 12 2022 @ 1433
 * Purpose:  Determine Min and Max of a set of #s
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <vector> 
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    short lowest, // lowest number
    highest; // highest number
    bool wntInpt; // want input - boolean for if user has entered -99 yet
    
    vector < short > nums; // due to nonpreset size, vector used over array
    
    //Initialize or input i.e. set variable values
    wntInpt = true; // want input 
    
    while (wntInpt) {
        short inpt; // termporary var for input
        cin >> inpt; // seek user input
        if (inpt != -99) nums.push_back(inpt); // if input isn't 99, add the inpt to the array
        else wntInpt = false; // stop seeking input
    }
    
    //Map inputs -> outputs
    //loop thru nums
    for (short i = 0; i < 5; i++) {
        // element needs to be sorted up
        if (nums[i] > nums[i+1]) {
            // swap num elements
            short tmpNm = nums[i];
            nums[i] = nums[i+1];
            nums[i+1] = tmpNm;
            
            //restart loop
            i = -1;
        }
    }
    
    //Display the outputs
    cout << "Smallest number in the series is " << nums.front() << endl;
    cout << "Largest  number in the series is " << nums.back();

    //Exit stage right or left!
    return 0;
}