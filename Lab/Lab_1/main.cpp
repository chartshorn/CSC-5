/* 
 * File:   main.cpp
 * Author: Caden Hartshorn
 * Created on June 22, 2022, 2015
 * Purpose: C++ Template - To be used in all future assignments
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "./Station.h"

//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    unsigned short tnkSz, //tank size in gallons 
        avgMpg, //car avg miles per gallon
        st1Dstnc,
        st1Prc,
        st2Dstnc,
        st2Prc;

    float gsGge, // % tank is full
        glnNd; // gallons of gas needed to fill tank
            
    
    //Initialize Variables
    avgMpg = 17; // 17 miles per gallon
    tnkSz = 22; // 22 gallon gas tank
    gsGge = 0.75f; // 75% full;
    
    st1Dstnc = 10; // 10 miles to station 1
    st1Prc = 4.25f; // $4.25/gal at station 1
    
    st2Dstnc = 20; // 20 miles to station 2
    st2Prc = 4.09f; // 4.09/gal at station 2
    
    glnNd = 22 * ( 1 - gsGge ); //multiply inverse of gas gauge by tankSize to gain gallons missing
    
    //Map inputs to outputs -> The Process
    //Initialize station instances and provide appropriate info
    // short distance, float price, float gallons needed, float avg mpg, string Station ID
    Station station1(10, 4.25f, glnNd, avgMpg, '1');
    Station station2(20, 4.09f, glnNd, avgMpg, '2');
    
    //Display Results
    station1.printDetails(); //Invoke print method
    station2.printDetails(); // ^
    
    //Exit stage right 
    return 0;
}

//Class Definition
