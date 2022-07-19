/* 
 * File:   main.cpp
 * Author: Caden Hartshorn
 * Created on July 02 2022 1937
 * Purpose: Calculate lethal dose of diet coke
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants
const float gPrPnd = 453.592f; // grams per pound
const float swtPrc = 0.001f; // 1/10 of 1%

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    float swtPrSd, // sweetener per soda
        hmWgtG, // desired weight (in grams)
        lRt, // lethal ratio (needed dose : mass)
        hmLthl, // lethal dose for a human
        msLthl; // lethal amount for a mouse
    unsigned short msWgt, // mouse weight (float for division)
        sdWgt, // soda weight
        hmWgt, // desired weight (in pounds)
        numCans; // number of cans you can safely drink
            
            
    
    //Initialize Variables
    //constants
    msLthl = 5; // 5 g of artificial sweetener to kill a mouse
    msWgt = 35; // mouse weighs 35 gs
    sdWgt = 350; //weight of the soda is 350g
    
    // calculate lethal ratio by dividing dose by mass
    lRt = msLthl / msWgt; // expressed in dose : mass
    
    //calculate sweetener per soda by multiplying weight of the soda by sweetener percentage
    swtPrSd = sdWgt * swtPrc;
    
    cout << "Program to calculate the limit of Soda Pop Consumption." << endl;
    cout << "Input the desired dieters weight in lbs." << endl;
    cin >> hmWgt;
    
    //Map inputs to outputs -> The Process
    //Convert human weight to grams
    hmWgtG = hmWgt * gPrPnd;
    
    //Calculate human weight by multiplying weight * lethal ratio
    hmLthl = hmWgtG * lRt;
    
    // calculate number of possible cans by dividing human lethal dose by sweetener in each soda
    numCans = hmLthl / swtPrSd;
    
    //Display Results
    cout << "The maximum number of soda pop cans" << endl;
    cout << "which can be consumed is " << numCans << " cans";
    
    //Exit stage right 
    return 0;
}

