/* 
 * File:   main.cpp
 * Author: Caden Hartshorn
 * Created on: July 23 2022 @ 1802
 * Purpose:Calculate the Standard Deviation
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
const float MAXRAND=pow(2,31)-1;

//Function Prototypes
void  init(float [],int);//Initialize the array
float avgX(float [],int);//Calculate the Average
float stdX(float [],int);//Calculate the standard deviation

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned>(time(0)));
    
    //Declare Variables
    const int SIZE=20; // size of the array
    float test[SIZE]; // array for the problem
    
    //Initialize or input i.e. set variable values
    init(test,SIZE);
    
    //Display the outputs
    cout << setprecision(7) << fixed;
    cout<<"The average            = "<<avgX(test,SIZE)<<endl;
    cout<<"The standard deviation = "<<stdX(test,SIZE)<<endl;

    //Exit stage right or left!
    return 0;
}

void init (float array[], int size) {
    // for each element in array, accept input
    for (short i = 0; i < size; i++) {
        cin >> array[i];
    }
}

float avgX (float array[], int size) {
    float mean; // average of all elements
    float sum = 0; // sum of all array elements
    
    //loop thru array; add each element to the sum
    for (short i =0; i < size; i++) {
        sum += array[i];
    }
    //calculate average by dividing sum by the number of terms 
    mean = sum/size;
    
    return mean;
}

float stdX (float array[], int size) {
    //init variables
    float sqSum = 0; // sum of the squares of all terms
    float mean = avgX(array, size); // average of all terms
    
    //loop through all array elements; add the the square sum the square of the element value minus the average
    //sum((x[i]-mean)^2/(n-1))
    for (short i = 0; i < size; i++) {
        sqSum += pow((array[i]-mean), 2);
    }

    return sqrt(sqSum / (size  - 1));
}