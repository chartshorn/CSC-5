/* 
 * File:   main.cpp
 * Author: Caden Hartshorn
 * Created on: July 23 2022 @ 1240
 * Purpose:  Linear Search
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <cstdlib>   //Random Functions
#include <ctime>     //Time Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
//Purpose: Fill a provided array with user Input
//Args: (int [] array - array to populate)
//Args: (int arrSz - size of the array)
void fillAry(int [],int);

//Purpose: Linearly search an array for provided values
//Args: (int [] array - array to search)
//Args: (int arrSz - size of the array)
//Args: (int val - value to search for)
//Args: (int &indx - index of the found value)
//Returns: (bool - if true, value was found, if false, value was not found)
bool linSrch(int [],int,int,int&);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int SIZE=100; // size of the array
    int array[SIZE]; // generate the array of provided size
    int indx,val; // index of search element, value to search for
    
    //Initialize or input i.e. set variable values
    val=50; // value to search for is 50
    fillAry(array,SIZE); // populate the array with user input
    
    //Display the outputs
    //Search the array for provided value
    if(linSrch(array,SIZE,val,indx))
        cout<<val<<" was found at indx = "<<indx<<endl;
    
    //Exit stage right or left!
    return 0;
}

//Purpose: Fill a provided array with user Input
void fillAry(int array[], int arrSz) {
    //loop thru the array; for each element, assign the user provided value
    for (short i = 0; i < arrSz; i++) {
        cin >> array[i];
    }
}

//Purpose: Linearly search an array for provided values
bool linSrch(int array[], int arrSz, int val, int &indx) {
    //loop thru the array starting at 0; if the value is found,
    //assign the index to the reference variable and return true
    //if the value is not found, return false
    for (short i = 0; i < arrSz; i++) {
        if (array[i] == val) {
            indx = i;
            return true;
        }
    }
    return false;
}