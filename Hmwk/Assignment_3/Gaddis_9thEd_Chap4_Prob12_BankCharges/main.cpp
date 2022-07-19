/* 
 * File:   main.cpp
 * Author: Caden Hartshorn
 * Created on July 08, 2022, 1500
 * Purpose: Calculate monthly fees of a bank
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
    float chks, // INPUT: number of checks written this month
    blnc, // INPUT: current account balance
    chkFee, // fee per check as calculated by program
    chkTtl, // total check fee
    ttlFee, // total fees incurred
    blncFee, // low balance fee
    mnthFee; // monthly fee
    
    //Initialize Variables
    // default values
    chkFee = 0.0f;
    ttlFee = 0.0f;
    blncFee = 0.0f;
    mnthFee = 10.0f; // $10 / mo fee
    
    cout << "Monthly Bank Fees" << endl;
    cout << "Input Current Bank Balance and Number of Checks" << endl;
    cin >> blnc >> chks;
    
    //input validation
    // cannot accept input with checks less than 0
    while (chks < 0) {
        cout << "** Error: You cannot provide a negative amount of checks. **" << endl;
        cin >> chks;
    }
    
    // if balance below zero inform user of overdraft
    if (blnc < 0) {
        cout << "*** YOUR ACCOUNT IS OVERDRAWN ***" << endl;
    }
    
    //Map inputs to outputs -> The Process
    //calculate low balance fee
    if (blnc < 400) {
        blncFee = 15.0f; // $15 fee if balance drops beneath $400
    }
    
    // calculate check fee
    if (chks < 20) chkFee = 0.1f; // 10 cents a check
    else if (chks >= 20 && chks < 40) chkFee = .08f; // 8 cents a check
    else if (chks >=40 && chks < 60) chkFee = .06f; // 6 cents a check
    else if (chks >=60) chkFee = .04f; // 4 cents a check
    else  return 1; // error case
    chkTtl = chks * chkFee; // total check cost =  written * check fee
    
    //add all fees
    ttlFee += blncFee; // total fee += low balance fee (? $15)
    ttlFee += chkTtl; // total fee += check fee
    ttlFee += mnthFee; // total fee += monthly fee ($10)
    
    //adjust Balance
    blnc -= ttlFee; // balance -= total fees
    
    //Display Results
    cout << fixed << showpoint << setprecision(2);
    cout << left << setw(12) << "Balance" << "$" << right << setw(9) << blnc+ttlFee << endl;
    cout << left << setw(12) << "Check Fee" << "$" << right << setw(9) << chkTtl << endl;
    cout << left << setw(12) << "Monthly Fee" << "$" << right << setw(9) << mnthFee << endl;
    cout << left << setw(12) << "Low Balance" << "$" << right << setw(9) << blncFee << endl;
    cout << left << setw(12) << "New Balance" << "$" << right << setw(9) << blnc;
    
    //Exit stage right 
    return 0;
}

