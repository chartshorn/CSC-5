/* 
 * File:   main.cpp
 * Author: Caden Hartshorn
 * Created on July 07 2346
 * Purpose: Calculate the percentage Gas Tax on a gallon of gas, and the profit made from a gallon of gas given
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
    float glPrc, // INPUT - gallon price
        ttlTx, // total tax
        olPrft, // 6.5% oil company profit
        slsTx, // 8% / gal state tax
        stTx, // static tax - state excise tax, trade fee, fed excise tax
        ttlOl, // total oil profit
        txPrt; // tax percent
    
    //Initialize Variables
    //tax variables
    //39 cents excise tax, 10 cents trade fee, and 18.4 cents fed excise tax fee / gallon
    stTx = .39f + .10f + .184f; 
    slsTx = .08f; // 8% tax / gal
    
    //oil  comp variables
    olPrft = .065f; // 6.5% profit margin
    
    //get user input
    cout << "Calculate Taxes and Profit on a Gallon of Gas" << endl;
    cout << "Enter the Price of a Gallon of Gas in USD" << endl;
    cin  >> glPrc; // user inputs gallon price
    
    //Map inputs to outputs -> The Process
    // add static tax to total tax
    ttlTx += stTx;
    
    //calc sales tax
    ttlTx += glPrc * slsTx; // total tax += gallon price * sales tax perc
    
    //calc total tax percentage
    txPrt = ( ttlTx / glPrc ) * 100;
    
    //calc oil profit;
    ttlOl = glPrc * olPrft; // total oil profit = gallon price * oil profit margin
    
    
    //Display Results
    cout << setprecision(3) << fixed << showpoint;
    cout << "-- Gallon Breakdown --" << endl;
    cout << left << setw(24) << "Total Taxes Extracted (" << txPrt << "%):";
    cout << right << "$" << setw(6) << ttlTx << endl;
    cout << left << setw(24) << "Total Oil Profit (6.5%):" << right << "$" << setw(6) << ttlOl;
    
    //Exit stage right 
    return 0;
}

