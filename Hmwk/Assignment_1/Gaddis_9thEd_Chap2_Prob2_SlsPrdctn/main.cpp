/* 
 * File:   main.cpp
 * Author: Caden Hartshorn
 * Created on June 22, 2022, 8:02 PM
 * Purpose: To determine the predicted sales of business divisions
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
    float estCstFctr; //percentage of sales that east coast contributes
    
    unsigned int cmpnySls, // predicted company sales
        estCstSls; // predicted east coast sales
    
    //Initialize Variables
    estCstFctr = 0.58f; // 58% of the company sales comes from the east coast div
    cmpnySls = 8600000; //8.6 million total sales in usd ($)
    
    //Map inputs to outputs -> The Process
    //Multiple companySales by the east coast factor
    estCstSls = cmpnySls * estCstFctr;
    
    //Display Results
    cout << "The East Coast division has an estimated sales total of: $";
    cout << setprecision(10) << estCstSls; //set precision to improve readability
    cout << endl;
    
    //Exit stage right 
    return 0;
}

