/* 
 * File:   main.cpp
 * Author: Caden Hartshorn
 * Created on July 8th 2022 @ 1656
 * Purpose: calculate internet bill
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    char plnId; // plan ID (A,B, or C)
    float pl1prc, // plan 1 monthly price
    pl2prc, // plan 2 monthly price
    pl3prc, // plan 3 monthly pirce
    pl1ad, // plan 1 additional hour cost
    pl2ad, // plan 2 additional hour cost
    prc; // total price
    short pl1hrs, // plan 1 included hrs
    pl2hrs, // plan 2 included hrs
    hrsUsd; // hours used
    bool invldNm;
    
    //Initialize Variables
    pl1prc = 9.95f; // $9.95 / mo
    pl2prc = 14.95f; // $ 14.95 / mo
    pl3prc = 19.95f; // $ 19.95 / mo
    pl1ad = 2.0f; // $2 extra / hr
    pl2ad = 1.0f; // $1 extra / hr
    pl1hrs = 10;
    pl2hrs = 20;
    
    //default values
    invldNm = true;
    
    //gather input
    cout << "ISP Bill" << endl;
    cout << "Input Package and Hours" << endl;
    cin >> plnId >> hrsUsd;
    
    //input alidation
    /*if ( ( plnId == 'A' || plnId == 'B' || plnId == 'C' ) && hrsUsd < 0 && hrsUsd > 744 ) {
        cout << "Invalid Plan Id or Hours Used";
        return 1;
    }*/

    //Map inputs to outputs -> The Process
    switch (plnId) {
        case 'A':
            prc += pl1prc; // add on base monthly price
            hrsUsd -= pl1hrs; // adjust hours based on included amnt
            prc += pl1ad * hrsUsd; // multiply additional hour cost by hours used
            break;
        case 'B':
            prc += pl2prc; // add on base monthly price
            hrsUsd -= pl2hrs; // adjust hours based on included amnt
            prc += pl2ad * hrsUsd; // multiply addtl hour cost by hours used
            break;
        case 'C':
            prc += pl3prc; // just 1 monthly price !
            break;
        default:
            break;
    }
    
    //Display Results
    cout << "Bill = $ " << setprecision(2) << showpoint << fixed << prc;

    //Exit stage right 
    return 0;
}