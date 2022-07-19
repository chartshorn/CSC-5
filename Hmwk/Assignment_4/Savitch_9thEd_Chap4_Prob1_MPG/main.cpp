/* 
 * File: main.cpp
 * Author: Caden Hartshorn
 * Created on July 12 2022 @ 1447
 * Purpose: calculate mpg of a car
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
const float lToG = .264179;

//Function Prototypes
// Purpose: Calculate mpg of a car and output associated data
// Inputs: ( character - id - id of the car to output )
// Returns: Float - Average MPG
float calcMpg(char); 

//Execution Begins Here!
int main(int argc, char** argv) {
    // loop controlling variable
    bool cnt = true;
    
    while (cnt) {
        //Declare Variables
        char yesNo; //usr input for yes no
        float mpg1, // mpg of car 1
        mpg2; // mpg of car 2
        
        mpg1 = calcMpg('1'); // calc mpg of car 1
        mpg2 = calcMpg('2'); // calc mpg of car 2
        
        //determine which car is more gas efficient
        if (mpg1 > mpg2) cout << "Car 1 is more fuel efficient" << endl;
        else if (mpg2 > mpg1) cout << "Car 2 is more fuel efficient" << endl;
        else cout << "MPG Error";
        cout << endl;
        
        //prompt user for second loop
        cout << "Again:" << endl;
        cin >> yesNo;
        
        //restart loop dependent on user input
        if (yesNo == 'y') {
            cout << endl;
        } else {
            cnt = false;
        }
    }
    
    //Exit stage right or left!
    return 0;
}

// Purpose: Calculate mpg of a car and output associated data
float calcMpg(char id) {
    short ltsCsm, // liters consumed 
    mlsTrv; // miles travelled
    float glns, // gallons consumed
    mpg; // avg mpg
    
    cout << "Car " << id << endl;
    cout << "Enter number of liters of gasoline:" << endl;
    cin >> ltsCsm;
    cout << "Enter number of miles traveled:" << endl;
    cin >> mlsTrv;
    
    //car 1 conversion
    glns = ltsCsm * lToG; // gallons = liters * liters to gallons factor
    mpg = mlsTrv / glns; // mpg = miles travelled / gallons
        
    //Display the outputs
    cout << "miles per gallon: ";
    cout << setprecision(2) << fixed << mpg;
    cout << endl << endl;
    
    return mpg; // return mpg for later comparison
}

