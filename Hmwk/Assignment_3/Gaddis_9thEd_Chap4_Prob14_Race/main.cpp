/* 
 * File:   main.cpp
 * Author: Caden Hartshorn
 * Created on July 8th 2022 @ 1621
 * Purpose: Calculate placings in a race
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void gatherInput(string [], short []);

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    string names [3] = {}; // array of runner names
    short times [3] = {}; // array of runner strings
    
    //Initialize Variables
    cout << "Race Ranking Program" << endl;
    cout << "Input 3 Runners" << endl;
    cout << "Their names, then their times" << endl;
    cin >> names[0] >> times[0] >>names[1] >> times[1] >> names[2] >> times[2];
    
    while (times[0] <= 0 || times[1] <= 0 || times[2] <= 0) {
        cout << "*** ERROR: Invalid Time ***";
        cout << "Input 3 Runners" << endl;
        cout << "Their names, then their times" << endl;
        cin >> names[0] >> times[0] >>names[1] >> times[1] >> names[2] >> times[2];
    }

    //Map inputs to outputs -> The Process
    //loop thru array
    for (short i = 0; i < 3; i++) {
        // element needs to be sorted up
        if (times[i] > times[i+1]) {
            // swap time elements
            short tmpTm = times[i];
            times[i] = times[i+1];
            times[i+1] = tmpTm;
            
            //swap name elements
            string tmpNm = names[i];
            names[i] = names[i+1];
            names[i+1] = tmpNm;
            
            //restart loop
            i = -1;
        }
    }
    
    //Display Results
    cout << names[0] << "\t" << setw(3) << times[0] << endl;
    cout << names[1] << "\t" << setw(3) << times[1] << endl;
    cout << names[2] << "\t" << setw(3) << times[2];
    
    //Exit stage right 
    return 0;
}

void gatherInput(string arr1[], short arr2[]) {
    cout << "Input 3 Runners" << endl;
    cout << "Their names, then their times" << endl;
    cin >> arr1[0] >> arr2[0] >>arr1[1] >> arr2[1] >> arr1[2] >> arr2[2];
}