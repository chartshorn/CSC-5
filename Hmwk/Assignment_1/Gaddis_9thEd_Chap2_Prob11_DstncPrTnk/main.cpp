/* 
 * File:   main.cpp
 * Author: Caden Hartshorn
 * Created on June 22, 2022, 2010
 * Purpose: Calculate a cars theoretical range
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
    unsigned short tnkSz, //Size of gas tank in gallons
        twnDstnc, //Distance the car can travel in town
        hwyDstnc; //Distance the car can travel on highway
    
    float twnAvg, //average MPG in town
        hwyAvg; //average MPG on highway
    
    //Initialize Variables
    tnkSz = 20; // 20 gallon gas tank
    twnAvg = 23.5f; // mpg in town
    hwyAvg = 28.9f; // mpg on highway
    
    //Map inputs to outputs -> The Process
    // multiply tank size by average mpg to determine miles possible to travel on
    twnDstnc = tnkSz * twnAvg; // the town roads
    hwyDstnc = tnkSz * hwyAvg; // & the highway
    
    //Display Results
    cout<<"You can travel "<<twnDstnc<<" miles in town"<<endl;
    cout<<"You can travel "<<hwyDstnc<<" miles on the highway"<<endl;
    
    //Exit stage right 
    return 0;
}

