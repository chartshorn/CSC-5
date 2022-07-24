/* 
 * File:   main.cpp
 * Author: Caden Hartshorn
 * Created: July 22 2022 @ 1604
 * Purpose:  Reverse an Array
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <cstdlib>   //Srand
#include <ctime>     //Time to set random number seed
#include <cmath>     //Math Library
#include <iomanip>   //Format Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
void  init(int [],int);//Initialize the array
void  print(int [],int,int);//Print the array
void  revrse(int [],int);;//Reverse the array


//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned>(time(0)));
    
    //Declare Variables
    const int SIZE=50; //size of the array
    int test[SIZE]; // input array
    
    //Initialize or input i.e. set variable values
    init(test,SIZE); 
    
    //Reverse the Values
    revrse(test,SIZE);
    
    //Display the outputs
    print(test,SIZE,10);

    //Exit stage right or left!
    return 0;
}

void init(int array[], int size) {
    // for each element in array, accept input
    for (short i = 0; i < size; i++) {
        cin >> array[i];
    }
}

void print (int array[], int size, int rowSize) {
    //for each element in array, print it plus a space to console
    for (short i = 0; i < size; i++) {
        cout << array[i] << " ";
        //output new line per problem specs
        if ((i+1) % rowSize == 0) cout << endl;
    }
}

void revrse(int array[], int size) {
    int rArray[size]; // reversed array
    //Loop through input array and assign reversed values to reverse array
    for (short i = 0; i < size; i++) {
        rArray[size-1-i] = array[i];
    }
    //Override normal order values in input array with reversed values
    for (short i = 0; i < size; i++) {
        array[i] = rArray[i];
    }
}