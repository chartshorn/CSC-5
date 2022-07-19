/* 
 * File:   main.cpp
 * Author: Caden Hartshorn
 * Created on July 08 2022 @ 1105
 * Purpose: Sort User Provided Names by Alpha
 */

//System Libraries
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //init random num seed
    
    //declare vars
    string name0, name1, name2;
    
    //Initialize or input i.e. set variable values
    cout << "Sorting Names" << endl;
    cout << "Input 3 names" << endl;
    cin >> name0 >> name1 >> name2;

    //Map inputs -> outputs
    //inputted names are in correct alpha order
    if (name0 <= name1 && name0 <= name2 && name1 <= name2) {
        cout << name0 << endl;
        cout << name1 << endl;
        cout << name2;
    // last name becomes 2nd name for correct alpha order
    } else if (name0 <= name1 && name0 <= name2 && name2 <= name1) {
        cout << name0 << endl;
        cout << name2 << endl;
        cout << name1;
    //middle name becomes first name for correct alpha order
    } else if (name1 <= name0 && name1 <= name2 && name0 <= name2) {
        cout << name1 << endl; 
        cout << name0 << endl;
        cout << name2;
    //first name becomes last name for correct alpha order
    } else if (name1 <= name0 && name1 <= name2 && name2 <= name0) {
        cout << name1 << endl; 
        cout << name2 << endl; 
        cout << name0;
    ///last name becomes first name, first name becomes middle name for correct alpha order
    } else if (name2 <= name0 && name2 <= name1 && name0 <= name1) {
        cout << name2 << endl;
        cout << name0 << endl;
        cout << name1;
    } else {
    //list reverses for correct alpha order
        cout << name2 << endl;
        cout << name1 << endl;
        cout << name0;
    }
    
    //Display the outputs
    // not / applicable

    //Exit stage right or left!
    return 0;
}