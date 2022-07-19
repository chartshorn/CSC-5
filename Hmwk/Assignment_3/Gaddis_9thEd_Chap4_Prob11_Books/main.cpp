/* 
 * File:   main.cpp
 * Author: Caden Hartshorn
 * Created on July 8 2022 @ 1147
 * Purpose:  Determine reward points for a bookstore
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    short nmBks, // number of books purchased
    pnts; // points awarded
    
    //Initialize or input i.e. set variable values
    cout << "Book Worm Points" << endl;
    cout << "Input the number of books purchased this month." << endl;
    cin >> nmBks;
    
    //Map inputs -> outputs
    if (nmBks == 0) pnts = 0; // 0 books 0 points
    else if (nmBks == 1) pnts = 5; // 1 book 5 points
    else if (nmBks == 2) pnts = 15; // 2 books 15 points
    else if (nmBks == 3) pnts = 30; // 3 books 30 points
    else if (nmBks >= 4) pnts = 60; // 4 books 60 points
    else return 0;
    
    //Display the outputs
    cout << left << setw(16) << "Books purchased" << "=" << right << setw(3) << nmBks << endl;;
    cout << left << setw(16) << "Points earned" << "=" << right << setw(3) << pnts;
    
    //Exit stage right or left!
    return 0;
}