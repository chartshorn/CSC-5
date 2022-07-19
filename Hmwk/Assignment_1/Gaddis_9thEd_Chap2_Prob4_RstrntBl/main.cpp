/* 
 * File:   main.cpp
 * Author: Caden Hartshorn
 * Created on June 22, 2022, 8:02 PM
 * Purpose: To calculate the tax and gratuity on a restaurant bill
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
    float mlCst, //price of food 
        txRt, // % tax rate
        txAmnt, // $ tax amount
        tpRt, // % gratuity rate
        tpAmnt, // gratuity
        ttl; // $ total  bill
    
    //Initialize Variables
    mlCst = 88.67f; // $88.67 purchase subtotal
    txRt = .0675f; // 6.75% tax rate
    tpRt = .20f; // 20% gratuity rate
    
    //Map inputs to outputs -> The Process
    //Calculate tax
    txAmnt = mlCst * txRt; // tax amount = meal cost * tax rate
    
    //Calculate tip
    tpAmnt = mlCst * tpRt; // tip amount = meal cost * gratuity rate
    
    //Compute bill
    ttl = mlCst + txAmnt + tpAmnt; // total bill = meal cost + tax amount + tip amount
    
    //Display Results
    cout
        <<"-=Your Bill=-"<<endl
        <<"--Meal Cost: $" << mlCst <<endl
        <<"--Taxes: $" << txAmnt << endl
        <<"--Gratuity: $"<< tpAmnt << endl
        <<"-=Total Bill: $" << ttl << endl;
    
    //Exit stage right 
    return 0;
}

