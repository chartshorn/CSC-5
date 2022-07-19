/* 
 * File:   main.cpp
 * Author: Caden Hartshorn
 * Created on July 02 2008
 * Purpose: Calculate a retroactive pay increase
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
    float pyInc, // pay increase 
        pyOwd, // pay owed
        nwSlryM, // new monthly salary
        nwSlry; // new salary
    unsigned short prvSlry; // previous salary
    
    //Initialize Variables
    pyInc = 0.076f; // 7.6 % pay raise retroactive 6 months
    
    cout << "Input previous annual salary." << endl;
    cin >> prvSlry;
    
    //Map inputs to outputs -> The Process
    nwSlry = prvSlry * (1+pyInc); // new salary = previous salary * the pay increase
    nwSlryM = nwSlry / 12; // new monthly salary = new annual salary / 12
    //pay owed = half of the difference of the new salary and the previous salary
    pyOwd = (nwSlry - prvSlry) / 2;
    
    //Display Results
    cout << setw(18) << left << "Retroactive pay" << " = $";
    cout << showpoint << fixed << setprecision(2) << setw(7) << right; // money formatting
    cout << pyOwd << endl; 
    cout << setw(18) << left << "New annual salary" << " = $";
    cout << showpoint << fixed << setprecision(2) << setw(7) << right; // money formatting
    cout << nwSlry << endl;
    cout << setw(18) << left << "New monthly salary" << " = $";
    cout << showpoint << fixed << setprecision(2) << setw(7) << right; // money formatting
    cout << nwSlryM;
    
    //Exit stage right 
    return 0;
}