/* 
 * File:   main.cpp
 * Author: Caden Hartshorn
 * Created on July 10 2022 @ 2032
 * Purpose:  Astrology compatability calculator
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <string>
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
string determineEl(string);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    string s1, s2, // user 1 sign, user 2 sign
    el1, el2; // sign 1 element, sign 2 element
    bool comp; // if the signs are compatible
    
    //Initialize or input i.e. set variable values
    cout << "Horoscope Program which examines compatible signs." << endl;
    cout << "Input 2 signs." << endl;
    cin >> s1 >> s2;
    
    //Map inputs -> outputs
    el1 = determineEl(s1);
    el2 = determineEl(s2);
    
    comp = el1 == el2 ? true : false;
    
    //Display the outputs
    cout << s1 << " and " << s2;
    if (comp) {
        cout << " are compatible " << el1 << " signs.";
    } else {
        cout << " are not compatible signs.";
    }

    //Exit stage right or left!
    return 0;
}

string determineEl(string sign) {
    //fire element
    if (sign == "Aries" || sign == "Leo" || sign == "Sagittarius") {
        return "Fire";
    //Earth Element
    } else if (sign == "Taurus" || sign == "Virgo" || sign == "Capricorn") {
        return "Earth";
    //Air Element
    } else if (sign == "Gemini" || sign == "Libra" || sign == "Aquarius") {
        return "Air";
    //Water Element
    } else if (sign == "Scorpio" || sign == "Pisces" || sign == "Cancer") {
        return "Water";
    //invalid sign        
    } else {
        return "Invalid Signs";
    }
}